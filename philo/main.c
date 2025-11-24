/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:36 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:03:23 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo_parameter	philo_parameter;
	t_threads_and_forks	threads_and_forks;

	arg_error_check(argc, argv);
	philo_parameter_init(argc, argv, &philo_parameter);
	philo_parameter_error_check(philo_parameter);
	threads_and_forks = alloc_threads_and_forks(philo_parameter.num_of_philo);
	do_philosopher(philo_parameter, threads_and_forks);
	free_all_and_exit(0, &threads_and_forks, philo_parameter.num_of_philo);
}
