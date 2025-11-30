/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:57:01 by kkido             #+#    #+#             */
/*   Updated: 2025/11/30 20:16:43 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_timer(t_philo_data *philo_data)
{
	long long	target_ms;
	long long	rem_ms;

	target_ms = get_time_in_ms() + philo_data->time_to_sleep;
	while (1)
	{
		rem_ms = target_ms - get_time_in_ms();
		if (rem_ms <= 0)
			break ;
		if (rem_ms >= 6)
			usleep(5000);
		else if (rem_ms >= 2)
			usleep(1000);
		else
			usleep(50);
	}
}

void	eat_timer(t_philo_data *philo_data)
{
	long long	target_ms;
	long long	now;
	long long	rem_ms;

	target_ms = get_time_in_ms() + philo_data->time_to_eat;
	while (1)
	{
		now = get_time_in_ms();
		rem_ms = target_ms - now;
		if (rem_ms <= 0)
			break ;
		if (rem_ms >= 6)
			usleep(5000);
		else if (rem_ms >= 2)
			usleep(1000);
		else
			usleep(50);
	}
}

void	mutexes_init(t_philo_data *philo_data, pthread_mutex_t *mutexes)
{
	int	i;

	i = 0;
	while (i < philo_data->num_of_philo)
	{
		if (pthread_mutex_init(&mutexes[i], NULL) != 0)
		{
			destroy_mutex_halfway(mutexes, i);
			free_philo_data_and_exit(4, philo_data);
		}
		i++;
	}
}
