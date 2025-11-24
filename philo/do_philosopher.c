/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:41:39 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:09:58 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_philosopher(t_philo_parameter philo_parameter,
		t_threads_and_forks threads_and_forks)
{
	t_philo	philo_all_info;
	int		i;

	i = 0;
	philo_all_info.philo_parameter = philo_parameter;
	philo_all_info.threads_and_forks = threads_and_forks;
	while (i < philo_parameter.num_of_philo)
}
