/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:44 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:03:41 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_error_check(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		free_all_and_exit(1, NULL, 0);
	while (i < argc)
	{
		is_natural_number(argv[i]);
		i++;
	}
}

void	is_natural_number(char *num)
{
	size_t	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' && num[i] > '9')
			free_all_and_exit(2, NULL, 0);
		i++;
	}
}

void	philo_parameter_error_check(t_philo_parameter param)
{
	if (param.num_of_philo < 0 || param.num_of_philo_must_eat < 0
		|| param.time_to_die < 0 || param.time_to_eat < 0
		|| param.time_to_sleep < 0)
		free_all_and_exit(2, NULL, 0);
}
