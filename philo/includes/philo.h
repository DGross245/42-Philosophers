/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:05:56 by dgross            #+#    #+#             */
/*   Updated: 2022/10/25 10:43:59 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

/////////////////////////////////////////////////////////////
//%%%					PHILO_STRUCT					%%%//
/////////////////////////////////////////////////////////////

typedef struct s_data
{
	int				nbr;
	int				times_eaten;
	pthread_t		thread;
}t_data;

/////////////////////////////////////////////////////////////
//%%%					MAIN_STRUCT						%%%//
/////////////////////////////////////////////////////////////

typedef struct s_philo
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				death;
	t_data			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}t_philo;

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

void				*routine(void *data);
int					write_function(t_philo	*philo, char *str);
int					eat_function(t_philo *philo);
int					think_function(t_philo	*philo);
int					sleep_function(t_philo	*philo);

/////////////////////////////////////////////////////////////
//%%%					  DEATH_TIME			 		%%%//
/////////////////////////////////////////////////////////////

//void				time_function();
//void				death_function();

/////////////////////////////////////////////////////////////
//%%%					CREATE_DESTROY					%%%//
/////////////////////////////////////////////////////////////

int					create(t_philo *philo);
int					destroy(t_philo *philo);
void				init_philo(t_philo	*philo, int argc, char **argv);

/////////////////////////////////////////////////////////////
//%%%						ERROR						%%%//
/////////////////////////////////////////////////////////////

int					error_check(int argc, char **argv);

#endif