/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:11:50 by kkido             #+#    #+#             */
/*   Updated: 2025/11/24 18:09:04 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo_parameter
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_philo_must_eat;
}						t_philo_parameter;

typedef struct s_threads_and_forks
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
}						t_threads_and_forks;

typedef struct s_philo
{
	t_philo_parameter	philo_parameter;
	t_threads_and_forks	threads_and_forks;
	int					philo_id;
}						t_philo;

// error_check.c
void					arg_error_check(int argc, char *argv[]);
void					is_natural_number(char *num);
void					philo_parameter_error_check(t_philo_parameter param);

// exit.c
void					free_all_and_exit(size_t id,
							t_threads_and_forks *threads_and_forks,
							int num_of_philo);
void					free_all_mem(size_t id,
							t_threads_and_forks *threads_and_forks,
							int num_of_philo);

// philo_utils.c
void					philo_parameter_init(int argc, char *argv[],
							t_philo_parameter *philo_parameter);
int						atoi_for_philo(char *nptr);
t_threads_and_forks		alloc_threads_and_forks(int num_of_philo);
void					destroy_mutex_halfway(pthread_mutex_t *forks,
							int init_to_this_point);

// do_philosopher.c
void					do_philosopher(t_philo_parameter philo_parameter,
							t_threads_and_forks threads_and_forks);

#endif
