/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:41:39 by kkido             #+#    #+#             */
/*   Updated: 2025/11/26 18:02:11 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_philosopher(t_philo_data *philo_data)
{
	t_philo	*philo_all_info;
	int		i;

	i = 0;
	philo_data->started_ms = get_time_in_ms();
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
	i = 0;
	while (i < philo_data->num_of_philo)
		pthread_join(philo_data->threads[i++], NULL);
	free(philo_all_info);
}

void	*entry_routine(void *philo_all_info_void)
{
	t_philo			*philo_info;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	philo_info = (t_philo *)philo_all_info_void;
	right_fork = &philo_info->philo_data->forks[philo_info->philo_id - 1];
	if (philo_info->philo_data->num_of_philo == 1)
	{
		alone_philosopher_routine(philo_info);
		return (NULL);
	}
	if (philo_info->philo_id % 2 == 0)
		even_philosopher_routine(philo_info);
	else
		odd_philosopher_routine(philo_info);
	return (NULL);
}

void	alone_philosopher_routine(t_philo *philo_all_info)
{
}

void	even_philosopher_routine(t_philo *philo_all_info)
{
}

void	odd_philosopher_routine(t_philo *philo_all_info)
{
}
