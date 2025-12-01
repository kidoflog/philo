/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:31 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 19:25:25 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo_data_and_return(size_t id, t_philo_data *philo_all_resources)
{
	free_all_mem(id, philo_all_resources);
	if (id == 0)
		return (0);
	if (id == 1)
	{
		write(2, "Usage: ./philo \"number_of_philosophers\" \"time_to_", 50);
		write(2, "die\" \"time_to_eat\" \"time_to_sleep\" ", 36);
		write(2, "(\"number_of_each_philosopher_must_eat\")\n", 41);
	}
	if (id == 2)
		write(2, "Error: Parameter must be natural number(1-2147483647).\n",
			56);
	if (id == 3 | id == 9)
		write(2, "Error: Memory allocation failed.\n", 34);
	if (id == 4 || id == 5 || id == 6 || id == 7)
		write(2, "Error: Mutex init failed\n", 26);
	if (id == 8)
		write(2, "Error: Get_time_of_day failed\n", 31);
	if (id == 10)
		write(2, "Error: Pthread_create failed\n", 29);
	return (1);
}

void	free_all_mem(size_t id, t_philo_data *philo_all_resources)
{
	int	i;

	i = 0;
	if (id == 1 || id == 2)
		return ;
	free_allocated_resources(philo_all_resources);
	if (id == 3 || id == 4)
		return ;
	destroy_all_mutexes(philo_all_resources, philo_all_resources->forks);
	if (id == 5)
		return ;
	destroy_all_mutexes(philo_all_resources, philo_all_resources->eat_locks);
	if (id == 6)
		return ;
	pthread_mutex_destroy(philo_all_resources->write_lock);
	if (id == 7)
		return ;
	pthread_mutex_destroy(philo_all_resources->someone_dead);
}

void	free_allocated_resources(t_philo_data *philo_data)
{
	if (philo_data->forks)
		free(philo_data->forks);
	if (philo_data->threads)
		free(philo_data->threads);
	if (philo_data->eat_locks)
		free(philo_data->eat_locks);
	if (philo_data->someone_dead)
		free(philo_data->someone_dead);
	if (philo_data->write_lock)
		free(philo_data->write_lock);
}

void	destroy_all_mutexes(t_philo_data *philo_data, pthread_mutex_t *mutexes)
{
	int	i;

	i = 0;
	while (i < philo_data->num_of_philo)
	{
		pthread_mutex_destroy(&mutexes[i]);
		i++;
	}
}
