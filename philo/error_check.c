/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:44 by kkido             #+#    #+#             */
/*   Updated: 2025/11/19 17:42:09 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_check(int argc, char *argv[])
{
	size_t	i;

	i = 1;
	if (argc != 5 && argc != 6)
		free_all_and_exit(1);
	while (i <= argc)
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
			free_all_and_exit(2);
		i++;
	}
}
