/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:37 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:02:11 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_parameter_init(int argc, char *argv[],
		t_philo_parameter *philo_parameter)
{
	size_t	i;

	i = 1;
	philo_parameter->num_of_philo = atoi_for_philo(argv[1]);
	philo_parameter->time_to_die = atoi_for_philo(argv[2]);
	philo_parameter->time_to_eat = atoi_for_philo(argv[3]);
	philo_parameter->time_to_sleep = atoi_for_philo(argv[4]);
	if (argc == 6)
		philo_parameter->num_of_philo_must_eat = atoi_for_philo(argv[5]);
	else
		philo_parameter->num_of_philo_must_eat = 0;
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

t_threads_and_forks	alloc_threads_and_forks(int num_of_philo)
{
	int					i;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	t_threads_and_forks	return_struct;

	i = 0;
	threads = malloc(sizeof(pthread_t) * num_of_philo);
	return_struct.threads = threads;
	forks = malloc(sizeof(pthread_mutex_t) * num_of_philo);
	return_struct.forks = forks;
	if (!threads || !forks)
		free_all_and_exit(3, &return_struct, num_of_philo);
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			destroy_mutex_halfway(forks, i);
			free_all_and_exit(4, &return_struct, num_of_philo);
		}
		i++;
	}
	return (return_struct);
}

void	destroy_mutex_halfway(pthread_mutex_t *forks, int init_to_this_point)
{
	int	i;

	i = 0;
	while (i < init_to_this_point)
		pthread_mutex_destroy(&forks[i++]);
}
