/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:13:31 by kkido             #+#    #+#             */
/*   Updated: 2025/11/19 17:32:08 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_and_exit(size_t id)
{
	if (id == 1)
		printf("Usage: ./philo \"number_of_philosophers\" \"time_to_die\" "
				"\"time_to_eat\" \"time_to_sleep\" "
				"(\"number_of_each_philosopher_must_eat\")\n");
	if (id == 2)
		printf("Error: Parameter should be natural number.");
	exit(1);
}
