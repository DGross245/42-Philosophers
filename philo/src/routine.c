/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:09:19 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 09:43:13 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	*routine(void *param)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)param;
	data = philo->data;
	philo->last_eat = time_function();
	if (philo->nbr % 2 == 0)
		entrance_blocker(philo);
	while (data->death != 1 && philo->times_eaten != data->max_eat)
	{
		if (eat_function(philo, data) == ERROR)
			break ;
		if (data->max_eat != philo->times_eaten)
		{
			if (sleep_function(philo, data) == ERROR)
				break ;
			if (think_function(philo, data) == ERROR)
				break ;
			usleep(500);
		}
	}
	return (NULL);
}

int	write_function(int nbr, t_data *data, char *str)
{
	pthread_mutex_lock(&data->write);
	if (data->death != 1)
		printf("%li %i %s\n", time_function() - data->start, nbr, str);
	pthread_mutex_unlock(&data->write);
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
