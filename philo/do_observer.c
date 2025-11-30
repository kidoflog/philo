/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_observer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:25:11 by kkido             #+#    #+#             */
/*   Updated: 2025/11/30 20:06:22 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_observer(t_philo_data *philo_data, t_philo *philo_all_info)
{
	pthread_t	observer;
	int			i;

	i = 0;
	pthread_create(&observer, NULL, (void *)&observer_routine, philo_all_info);
	while (i < philo_data->num_of_philo)
		pthread_join(philo_data->threads[i++], NULL);
	philo_data->is_dead = 1;
	pthread_join(observer, NULL);
}

void	*observer_routine(void *philo_all_info_void)
{
	t_philo_data	*philo_data;
	int				i;
	long long		time_to_die;
	t_philo			*philo_all_info;

	philo_all_info = (t_philo *)philo_all_info_void;
	philo_data = philo_all_info->philo_data;
	time_to_die = philo_data->time_to_die;
	while (is_dead_check(philo_data) == 0)
	{
		i = 0;
		while (i < philo_data->num_of_philo)
		{
			if (get_passed_time(philo_all_info[i].ate_ms) >= time_to_die)
			{
				print_dead(&philo_all_info[i]);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
