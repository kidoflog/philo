/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:36 by kkido             #+#    #+#             */
/*   Updated: 2025/11/19 18:09:05 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo_parameter	philo_parameter;

	error_check(argc, argv);
	philo_parameter_init(argc, argv, &philo_parameter);
}
