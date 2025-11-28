/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:11:50 by kkido             #+#    #+#             */
/*   Updated: 2025/11/27 18:48:03 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	pthread_t		*threads;
	pthread_t       *is_printf_print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*someone_dead;
	long long		started_ms;
	int				philo_exit_id;

}					t_philo_data;

typedef struct s_philo
{
	t_philo_data	*philo_data;
	int				philo_id;
	long long		ate_ms;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

// error_check.c
void				arg_error_check(int argc, char *argv[]);
void				is_natural_number(char *num);
void				philo_parameter_error_check(t_philo_data param);

// exit.c
void				free_philo_data_and_exit(size_t id,
						t_philo_data *philo_all_resources);
void				free_all_mem(size_t id, t_philo_data *philo_all_resources);

// philo_utils.c
void				philo_parameter_init(int argc, char *argv[],
						t_philo_data *philo_parameter);
int					atoi_for_philo(char *nptr);
void				alloc_philo_resources(t_philo_data *philo_all_info);
void				destroy_mutex_halfway(pthread_mutex_t *forks,
						int init_to_this_point);
long long			get_time_in_ms(void);

// do_philosopher.c
void				do_philosopher(t_philo_data *philo_data);
void				*entry_routine(void *philo_all_info_void);
void				alone_philosopher_routine(t_philo *philo_all_info);

#endif
