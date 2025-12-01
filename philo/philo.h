/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:11:50 by kkido             #+#    #+#             */
/*   Updated: 2025/12/01 19:27:42 by kkido            ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	*eat_locks;
	pthread_mutex_t	*write_lock;
	int				is_dead;
	pthread_mutex_t	*someone_dead;
	long long		started_ms;

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
int					arg_error_check(int argc, char *argv[]);
int					is_natural_number(char *num);
int					philo_parameter_error_check(t_philo_data param, int argc);

// exit.c
int					free_philo_data_and_return(size_t id,
						t_philo_data *philo_all_resources);
void				free_all_mem(size_t id, t_philo_data *philo_all_resources);
void				destroy_all_mutexes(t_philo_data *philo_data,
						pthread_mutex_t *mutexes);
void				free_allocated_resources(t_philo_data *philo_data);

// philo_utils.c
void				philo_parameter_init(int argc, char *argv[],
						t_philo_data *philo_parameter);
int					atoi_for_philo(char *nptr);
int					alloc_philo_resources(t_philo_data *philo_all_info);
void				destroy_mutex_halfway(pthread_mutex_t *forks,
						int init_to_this_point);
long long			get_time_in_ms(void);

// philo_utils2.c
long long			get_passed_time(long long started_time);
int					is_dead_check(t_philo_data *philo_data);
void				philo_dead(t_philo_data *philo_data);
void				wait_until_start(t_philo_data *philo_data);

// philo_utils3.c
void				sleep_timer(t_philo_data *philo_data);
void				eat_timer(t_philo_data *philo_data);
int					mutexes_init(t_philo_data *philo_data,
						pthread_mutex_t *mutexes);
int					creation_error(t_philo *philo_all_info,
						t_philo_data *philo_data, int to_this_point);

// do_philosopher.c
int					do_philosopher(t_philo_data *philo_data);
void				*entry_routine(void *philo_all_info_void);
void				alone_philosopher_routine(t_philo *philo_info,
						t_philo_data *philo_data);
void				even_philosopher_routine(t_philo *philo_info,
						t_philo_data *philo_data);
void				odd_philosopher_routine(t_philo *philo_info,
						t_philo_data *philo_data);

// philo_fanc.c
void				print_take_fork(t_philo *philo_info);
void				do_sleep(t_philo *philo_info);
void				do_eat(t_philo *philo_info);
void				print_think(t_philo *philo_info);
void				print_dead(t_philo *philo_info);

// do_observer.c
int					do_observer(t_philo_data *philo_data,
						t_philo *philo_all_info);
void				*observer_routine(void *philo_all_info_void);
#endif
