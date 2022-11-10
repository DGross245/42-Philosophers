/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:36 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 15:49:05 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	write_function(int nbr, t_data *data, char *str)
{
	pthread_mutex_lock(&data->write);
	pthread_mutex_lock(&data->dead);
	if (data->death != 1)
		printf("%li %i %s\n", time_function() - data->start, nbr, str);
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->dead);
	return (0);
}

int	sleep_function(t_philo	*philo, t_data *data)
{
	write_function(philo->nbr, data, "is sleeping");
	ft_usleep(data->time_to_sleep);
	return (0);
}

int	think_function(t_philo	*philo, t_data *data)
{
	write_function(philo->nbr, data, "is thinking");
	return (0);
}

void	eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->eat);
	philo->last_eat = time_function();
	write_function(philo->nbr, data, "is eating");
	philo->times_eaten++;
	pthread_mutex_unlock(&data->eat);
}

int	eat_function(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left]);
	write_function(philo->nbr, data, "has taken a fork");
	if (data->philo_nbr == 1)
	{
		pthread_mutex_unlock(&data->forks[philo->left]);
		return (ERROR);
	}
	pthread_mutex_lock(&data->forks[philo->right]);
	write_function(philo->nbr, data, "has taken a fork");
	eat(philo, data);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->left]);
	pthread_mutex_unlock(&data->forks[philo->right]);
	return (0);
}
