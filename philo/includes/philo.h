/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:05:56 by dgross            #+#    #+#             */
/*   Updated: 2022/11/01 11:11:19 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# ifndef ERROR
#  define ERROR -1
# endif

/////////////////////////////////////////////////////////////
//%%%					PHILO_STRUCT					%%%//
/////////////////////////////////////////////////////////////

typedef struct s_philo
{
	int				nbr;
	int				times_eaten;
	long			last_eat;
	int				left;
	int				right;
	pthread_t		thread;
	struct s_data	*data;
}t_philo;

/////////////////////////////////////////////////////////////
//%%%					MAIN_STRUCT						%%%//
/////////////////////////////////////////////////////////////

typedef struct s_data
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				death;
	long			start;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}t_data;

/////////////////////////////////////////////////////////////
//%%%						  UTILS						%%%//
/////////////////////////////////////////////////////////////

int					ft_atoi(const char	*str);
int					ft_isdigit(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_malloc(size_t size);

/////////////////////////////////////////////////////////////
//%%%						ROUTINE						%%%//
/////////////////////////////////////////////////////////////

void				*routine(void *philo);
int					write_function(int nbr, t_data	*data, char *str);
int					eat_function(t_philo *philo, t_data *data);
int					think_function(t_philo *philo, t_data	*data);
int					sleep_function(t_philo *philo, t_data	*data);

/////////////////////////////////////////////////////////////
//%%%					  DEATH_TIME			 		%%%//
/////////////////////////////////////////////////////////////

long				time_function(void);
void				death_function(t_data *data);
int					food_checker(t_data *data);
long				get_time_dif(long time, t_data *data);

/////////////////////////////////////////////////////////////
//%%%					CREATE_DESTROY					%%%//
/////////////////////////////////////////////////////////////

int					create(t_data *data);
int					destroy(t_data *data);
void				init_data(t_data	*data, int argc, char **argv);
void				init_philo(t_data *data);

/////////////////////////////////////////////////////////////
//%%%						ERROR						%%%//
/////////////////////////////////////////////////////////////

int					error_check(int argc, char **argv);
void				entrance_blocker(t_philo *philo);

void				ft_usleep(long int time_in_ms);

#endif