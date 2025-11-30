/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:41:39 by kkido             #+#    #+#             */
/*   Updated: 2025/11/30 14:49:00 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_philosopher(t_philo_data *philo_data)
{
	t_philo	*philo_all_info;
	int		i;

	i = 0;
	philo_data->started_ms = get_time_in_ms() + 1000;
	if (philo_data->started_ms < 0)
		free_philo_data_and_exit(6, philo_data);
	philo_all_info = malloc(sizeof(t_philo) * philo_data->num_of_philo);
	if (!philo_all_info)
		free_philo_data_and_exit(7, philo_data);
	while (i < philo_data->num_of_philo)
	{
		philo_all_info[i].philo_id = i + 1;
		philo_all_info[i].ate_ms = philo_data->started_ms;
		philo_all_info[i].philo_data = philo_data;
		pthread_create(&philo_data->threads[i], NULL, &entry_routine,
			&philo_all_info[i]);
		i++;
	}
	do_observer(philo_data, philo_all_info);
	free(philo_all_info);
}

void	*entry_routine(void *philo_all_info_void)
{
	t_philo			*philo_info;
	t_philo_data	*philo_data;

	philo_info = (t_philo *)philo_all_info_void;
	philo_data = philo_info->philo_data;
	philo_info->right_fork = &philo_data->forks[philo_info->philo_id - 1];
	if (philo_data->num_of_philo == 1)
	{
		alone_philosopher_routine(philo_info, philo_data);
		return (NULL);
	}
	if (philo_info->philo_id == philo_info->philo_data->num_of_philo)
		philo_info->left_fork = &philo_info->philo_data->forks[0];
	else
		philo_info->left_fork = &philo_data->forks[philo_info->philo_id];
	if (philo_info->philo_id % 2 == 0)
		even_philosopher_routine(philo_info, philo_data);
	else
		odd_philosopher_routine(philo_info, philo_data);
	return (NULL);
}

void	alone_philosopher_routine(t_philo *philo_info, t_philo_data *philo_data)
{
	wait_until_start(philo_data);
	pthread_mutex_lock(philo_info->right_fork);
	print_take_fork(philo_info);
	while (get_passed_time(philo_data->started_ms) >= philo_data->time_to_die)
		usleep(100);
	print_dead(philo_info);
	pthread_mutex_unlock(philo_info->right_fork);
	pthread_mutex_lock(philo_info->philo_data->someone_dead);
}

void	even_philosopher_routine(t_philo *philo_info, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	wait_until_start(philo_data);
	while (is_dead_check(philo_data) == 0)
	{
		pthread_mutex_lock(philo_info->right_fork);
		print_take_fork(philo_info);
		pthread_mutex_lock(philo_info->left_fork);
		print_take_fork(philo_info);
		philo_info->ate_ms = get_time_in_ms();
		print_eat(philo_info);
		eat_timer(philo_data);
		pthread_mutex_unlock(philo_info->right_fork);
		pthread_mutex_unlock(philo_info->left_fork);
		if (i > philo_data->num_of_philo_must_eat)
		{
			printf("even break\n");
			break ;
		}
		print_sleep(philo_info);
		sleep_timer(philo_data);
		print_think(philo_info);
		i++;
	}
}

void	odd_philosopher_routine(t_philo *philo_info, t_philo_data *philo_data)
{
	int	i;

	i = 0;
	wait_until_start(philo_data);
	usleep(3000);
	while (is_dead_check(philo_data) == 0)
	{
		print_think(philo_info);
		pthread_mutex_lock(philo_info->left_fork);
		print_take_fork(philo_info);
		pthread_mutex_lock(philo_info->right_fork);
		print_take_fork(philo_info);
		philo_info->ate_ms = get_time_in_ms();
		print_eat(philo_info);
		eat_timer(philo_data);
		pthread_mutex_unlock(philo_info->right_fork);
		pthread_mutex_unlock(philo_info->left_fork);
		if (i > philo_data->num_of_philo_must_eat)
			break ;
		print_sleep(philo_info);
		sleep_timer(philo_data);
		i++;
	}
}
