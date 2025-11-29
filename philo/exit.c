/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:31 by kkido             #+#    #+#             */
/*   Updated: 2025/11/29 14:25:27 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_data_and_exit(size_t id, t_philo_data *philo_all_resources)
{
	free_all_mem(id, philo_all_resources);
	if (id == 0)
		exit(0);
	if (id == 1)
	{
		write(2, "Usage: ./philo \"number_of_philosophers\" \"time_to_", 50);
		write(2, "die\" \"time_to_eat\" \"time_to_sleep\" ", 36);
		write(2, "(\"number_of_each_philosopher_must_eat\")\n", 41);
	}
	if (id == 2)
		write(2, "Error: Parameter must be natural number(1-2147483647).\n",
			56);
	if (id == 3 | id == 7)
		write(2, "Error: Memory allocation failed.\n", 34);
	if (id == 4 || id == 5)
		write(2, "Error: Mutex init failed\n", 26);
	if (id == 6)
		write(2, "Error: Get_time_of_day failed\n", 31);
	exit(1);
}

void	free_all_mem(size_t id, t_philo_data *philo_all_resources)
{
	int	i;

	i = 0;
	if (id == 1 || id == 2)
		return ;
	if (id != 3 && id != 4)
	{
		while (i < philo_all_resources->num_of_philo)
			pthread_mutex_destroy(&philo_all_resources->forks[i++]);
		if (id != 5)
		{
			if (id != 8)
				pthread_mutex_destroy(philo_all_resources->write_lock);
			pthread_mutex_destroy(philo_all_resources->someone_dead);
		}
	}
	if (philo_all_resources->forks)
		free(philo_all_resources->forks);
	if (philo_all_resources->threads)
		free(philo_all_resources->threads);
	if (philo_all_resources->someone_dead)
		free(philo_all_resources->someone_dead);
	if (philo_all_resources->write_lock)
		free(philo_all_resources->write_lock);
}
