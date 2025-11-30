/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:37 by kkido             #+#    #+#             */
/*   Updated: 2025/11/30 20:19:31 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_parameter_init(int argc, char *argv[],
		t_philo_data *philo_parameter)
{
	philo_parameter->num_of_philo = atoi_for_philo(argv[1]);
	philo_parameter->time_to_die = atoi_for_philo(argv[2]);
	philo_parameter->time_to_eat = atoi_for_philo(argv[3]);
	philo_parameter->time_to_sleep = atoi_for_philo(argv[4]);
	if (argc == 6)
		philo_parameter->num_of_philo_must_eat = atoi_for_philo(argv[5]);
	else
		philo_parameter->num_of_philo_must_eat = 0;
	philo_parameter->philo_exit_id = 0;
	philo_parameter->is_dead = 0;
}

int	atoi_for_philo(char *nptr)
{
	long long	result_num;
	size_t		i;

	result_num = 0;
	i = 0;
	if (nptr[0] == '0')
		return (-1);
	while (nptr[i])
	{
		result_num = result_num * 10 + (nptr[i] - '0');
		if (result_num > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)result_num);
}

void	alloc_philo_resources(t_philo_data *philo_data)
{
	int	i;

	i = 0;
	philo_data->threads = malloc(sizeof(pthread_t) * philo_data->num_of_philo);
	philo_data->forks = malloc(sizeof(pthread_mutex_t)
			* philo_data->num_of_philo);
	philo_data->someone_dead = malloc(sizeof(pthread_mutex_t));
	philo_data->write_lock = malloc(sizeof(pthread_mutex_t));
	philo_data->eat_locks = malloc(sizeof(pthread_mutex_t)
			* philo_data->num_of_philo);
	if (!philo_data->threads || !philo_data->forks || !philo_data->someone_dead)
		free_philo_data_and_exit(3, philo_data);
	mutexes_init(philo_data, philo_data->forks);
	mutexes_init(philo_data, philo_data->eat_locks);
	if (pthread_mutex_init(philo_data->someone_dead, NULL) != 0)
		free_philo_data_and_exit(5, philo_data);
	if (pthread_mutex_init(philo_data->write_lock, NULL) != 0)
		free_philo_data_and_exit(8, philo_data);
}

void	destroy_mutex_halfway(pthread_mutex_t *forks, int init_to_this_point)
{
	int	i;

	i = 0;
	while (i < init_to_this_point)
		pthread_mutex_destroy(&forks[i++]);
}

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
