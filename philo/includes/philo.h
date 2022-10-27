/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:05:56 by dgross            #+#    #+#             */
/*   Updated: 2022/10/27 17:46:52 by dgross           ###   ########.fr       */
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
	int				last_eat;
	int				left;
	int				right;
	pthread_t		thread;
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
int					write_function(t_data	*data, char *str);
int					eat_function(t_data *data);
int					think_function(t_data	*data);
int					sleep_function(t_data	*data);

/////////////////////////////////////////////////////////////
//%%%					  DEATH_TIME			 		%%%//
/////////////////////////////////////////////////////////////

long				time_funciton(void);
//void				death_function();

/////////////////////////////////////////////////////////////
//%%%					CREATE_DESTROY					%%%//
/////////////////////////////////////////////////////////////

int					create(t_data *data);
int					destroy(t_data *data);
void				init_philo(t_data	*data, int argc, char **argv);

/////////////////////////////////////////////////////////////
//%%%						ERROR						%%%//
/////////////////////////////////////////////////////////////

int					error_check(int argc, char **argv);

#endif