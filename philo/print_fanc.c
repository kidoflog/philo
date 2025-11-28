/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fanc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:27:41 by kkido             #+#    #+#             */
/*   Updated: 2025/11/28 18:59:52 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_take_fork(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->philo_data->write_lock);
	if (is_dead_check(philo_info->philo_data) == 0)
		printf("%lld %d has taken a fork\n",
			get_passed_time(philo_info->philo_data->started_ms),
			philo_info->philo_id);
	pthread_mutex_unlock(philo_info->philo_data->write_lock);
}

void	print_eat(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->philo_data->write_lock);
	if (is_dead_check(philo_info->philo_data) == 0)
		printf("%lld %d is eating\n",
			get_passed_time(philo_info->philo_data->started_ms),
			philo_info->philo_id);
	pthread_mutex_unlock(philo_info->philo_data->write_lock);
}

void	print_sleep(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->philo_data->write_lock);
	if (is_dead_check(philo_info->philo_data) == 0)
		printf("%lld %d is sleeping\n",
			get_passed_time(philo_info->philo_data->started_ms),
			philo_info->philo_id);
	pthread_mutex_unlock(philo_info->philo_data->write_lock);
}

void	print_think(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->philo_data->write_lock);
	if (is_dead_check(philo_info->philo_data) == 0)
		printf("%lld %d is thinking\n",
			get_passed_time(philo_info->philo_data->started_ms),
			philo_info->philo_id);
	pthread_mutex_unlock(philo_info->philo_data->write_lock);
}

void	print_dead(t_philo *philo_info)
{
	pthread_mutex_lock(philo_info->philo_data->write_lock);
	if (is_dead_check(philo_info->philo_data) == 0)
		printf("%lld %d died\n",
			get_passed_time(philo_info->philo_data->started_ms),
			philo_info->philo_id);
	philo_dead(philo_info->philo_data);
	pthread_mutex_unlock(philo_info->philo_data->write_lock);
}
