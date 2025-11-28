/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:12:30 by kkido             #+#    #+#             */
/*   Updated: 2025/11/28 19:06:02 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_passed_time(long long started_time)
{
	return (get_time_in_ms() - started_time);
}

int	is_dead_check(t_philo_data *philo_data)
{
	int	is_dead;

	pthread_mutex_lock(philo_data->someone_dead);
	is_dead = philo_data->is_dead;
	pthread_mutex_unlock(philo_data->someone_dead);
	return (is_dead);
}

void	philo_dead(t_philo_data *philo_data)
{
	pthread_mutex_lock(philo_data->someone_dead);
	philo_data->is_dead = 1;
	pthread_mutex_unlock(philo_data->someone_dead);
}
