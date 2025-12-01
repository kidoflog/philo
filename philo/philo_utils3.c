/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:57:01 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 19:27:23 by kkido            ###   ########.fr       */
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
			usleep(100);
	}
}

void	eat_timer(t_philo_data *philo_data)
{
	long long	target_ms;
	long long	rem_ms;

	target_ms = get_time_in_ms() + philo_data->time_to_eat;
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
			usleep(100);
	}
}

int	mutexes_init(t_philo_data *philo_data, pthread_mutex_t *mutexes)
{
	int	i;

	i = 0;
	while (i < philo_data->num_of_philo)
	{
		if (pthread_mutex_init(&mutexes[i], NULL) != 0)
		{
			destroy_mutex_halfway(mutexes, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	creation_error(t_philo *philo_all_info, t_philo_data *philo_data,
		int to_this_point)
{
	int	i;

	pthread_mutex_lock(philo_data->someone_dead);
	philo_data->is_dead = 1;
	pthread_mutex_unlock(philo_data->someone_dead);
	i = 0;
	while (i < to_this_point)
	{
		pthread_join(philo_data->threads[i], NULL);
		i++;
	}
	free(philo_all_info);
	return (10);
}
