/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:44 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 18:36:30 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_error_check(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc)
	{
		if (is_natural_number(argv[i]) != 0)
			return (2);
		i++;
	}
	return (0);
}

int	is_natural_number(char *num)
{
	size_t	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	philo_parameter_error_check(t_philo_data param, int argc)
{
	if (param.num_of_philo < 0 || (argc == 6 && param.num_of_philo_must_eat < 0)
		|| param.time_to_die < 0 || param.time_to_eat < 0
		|| param.time_to_sleep < 0)
		return (2);
	return (0);
}
