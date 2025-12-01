/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:36 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 19:01:27 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int				return_value;
	t_philo_data	philo_data;

	return_value = arg_error_check(argc, argv);
	if (return_value != 0)
		return (free_philo_data_and_return(return_value, NULL));
	philo_parameter_init(argc, argv, &philo_data);
	return_value = philo_parameter_error_check(philo_data, argc);
	if (return_value != 0)
		return (free_philo_data_and_return(return_value, NULL));
	return_value = alloc_philo_resources(&philo_data);
	if (return_value != 0)
		return (free_philo_data_and_return(return_value, &philo_data));
	return_value = do_philosopher(&philo_data);
	if (return_value != 0)
		return (free_philo_data_and_return(return_value, &philo_data));
	free_philo_data_and_return(0, &philo_data);
}
