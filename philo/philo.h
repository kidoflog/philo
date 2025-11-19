/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:11:50 by kkido             #+#    #+#             */
/*   Updated: 2025/11/19 18:12:11 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo_parameter
{
	size_t	number_of_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_each_philosopher_must_eat;
}			t_philo_parameter;

void		free_all_and_exit(size_t id);
void		error_check(int argc, char *argv[]);
void		philo_parameter_init(int argc, char *argv[],
				t_philo_parameter *philo_parameter);

#endif
