/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:15:00 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 13:59:12 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

long	time_function(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

void	death_function(t_data *data)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < data->philo_nbr && data->death != 1)
		{
			pthread_mutex_lock(&data->eat);
			if ((time_function() - data->philo[i].last_eat) > data->time_to_die)
			{
				write_function(data->philo[i].nbr, data, \
				"\033[0;31mis dead\033[0m");
				pthread_mutex_lock(&data->dead);
				data->death = 1;
				pthread_mutex_unlock(&data->dead);
				pthread_mutex_unlock(&data->eat);
				break ;
			}	
			pthread_mutex_unlock(&data->eat);
		}
		if (data->death == 1)
			break ;
		if (data->max_eat != -1 && food_checker(data) == data->philo_nbr)
			break ;
	}
}

int	food_checker(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_lock(&(data->eat));
		if (data->philo[i].times_eaten != data->max_eat)
		{
			pthread_mutex_unlock(&(data->eat));
			return (i);
		}
		pthread_mutex_unlock(&(data->eat));
		i++;
	}
	return (i);
}
