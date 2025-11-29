/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:57:01 by kkido             #+#    #+#             */
/*   Updated: 2025/11/29 14:25:56 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_timer(t_philo_data *philo_data)
{
	long long	sleep_start_time;

	sleep_start_time = get_time_in_ms();
	while (get_time_in_ms() - sleep_start_time < philo_data->time_to_sleep)
		usleep(50);
}

void	eat_timer(t_philo_data *philo_data)
{
	long long	eat_start_time;

	eat_start_time = get_time_in_ms();
	while (get_time_in_ms() - eat_start_time < philo_data->time_to_eat)
		usleep(50);
}
