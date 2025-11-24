/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:31 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:04:09 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_and_exit(size_t id, t_threads_and_forks *threads_and_forks,
		int num_of_philo)
{
	free_all_mem(id, threads_and_forks, num_of_philo);
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
	if (id == 3)
		write(2, "Error: Memory allocation failed.\n", 34);
	if (id == 4)
		write(2, "Error: Mutex init failed\n", 26);
	exit(1);
}

void	free_all_mem(size_t id, t_threads_and_forks *threads_and_forks,
		int num_of_philo)
{
	int	i;

	i = 0;
	if (id == 1 || id == 2)
		return ;
	if (id != 3 && id != 4)
	{
		while (i < num_of_philo)
			pthread_mutex_destroy(&threads_and_forks->forks[i++]);
	}
	if (threads_and_forks)
	{
		if (threads_and_forks->forks)
			free(threads_and_forks->forks);
		if (threads_and_forks->threads)
			free(threads_and_forks->threads);
	}
}
