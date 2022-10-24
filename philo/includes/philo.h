/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:05:56 by dgross            #+#    #+#             */
/*   Updated: 2022/10/24 10:26:07 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
typedef struct s_data
{
	int			nbr;
}t_data;

typedef struct s_philo
{
	pthread_t		*thread_arr;
	pthread_mutex_t *mutex_arr;
	t_data			*philo;
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
}t_philo;

void	*ft_malloc(size_t size);
int		ft_atoi(const char	*str);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
#endif