/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_observer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:25:11 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 19:25:38 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_observer(t_philo_data *philo_data, t_philo *philo_all_info)
{
	pthread_t	observer;
	int			i;
	int			return_value;

	return_value = 0;
	i = 0;
	if (pthread_create(&observer, NULL, (void *)&observer_routine,
			philo_all_info) != 0)
	{
		pthread_mutex_lock(philo_data->someone_dead);
		philo_data->is_dead = 1;
		pthread_mutex_unlock(philo_data->someone_dead);
		return_value = 10;
	}
	while (i < philo_data->num_of_philo)
		pthread_join(philo_data->threads[i++], NULL);
	pthread_mutex_lock(philo_data->someone_dead);
	philo_data->is_dead = 1;
	pthread_mutex_unlock(philo_data->someone_dead);
	pthread_join(observer, NULL);
	free(philo_all_info);
	return (return_value);
}

void	*observer_routine(void *philo_all_info_void)
{
	int			i;
	long long	time_to_die;
	t_philo		*philo_all_info;

	philo_all_info = (t_philo *)philo_all_info_void;
	time_to_die = philo_all_info->philo_data->time_to_die;
	while (is_dead_check(philo_all_info->philo_data) == 0)
	{
		i = 0;
		while (i < philo_all_info->philo_data->num_of_philo)
		{
			pthread_mutex_lock(&philo_all_info->philo_data->eat_locks[i]);
			if (get_passed_time(philo_all_info[i].ate_ms) >= time_to_die)
			{
				print_dead(&philo_all_info[i]);
				pthread_mutex_unlock(&philo_all_info->philo_data->eat_locks[i]);
				return (NULL);
			}
			pthread_mutex_unlock(&philo_all_info->philo_data->eat_locks[i]);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
