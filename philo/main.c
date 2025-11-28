/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:36 by kkido             #+#    #+#             */
/*   Updated: 2025/11/28 16:17:14 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// exitの修正！
int	main(int argc, char *argv[])
{
	int				return_status;
	t_philo_data	philo_data;

	return_status = 0;
	arg_error_check(argc, argv);
	philo_parameter_init(argc, argv, &philo_data);
	philo_parameter_error_check(philo_data);
	alloc_philo_resources(&philo_data);
	do_philosopher(&philo_data);
	free_philo_data_and_exit(philo_data.philo_exit_id, &philo_data);
}
