/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:09:19 by dgross            #+#    #+#             */
/*   Updated: 2022/11/01 11:09:24 by dna              ###   ########.fr       */
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
	if (philo->nbr % 2 == 0)
		entrance_blocker(philo);
	philo->times_eaten = 0;
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
		}
	}
	return (NULL);
}

int	write_function(int nbr, t_data *data, char *str)
{
	if (data->death != 1)
	{
		pthread_mutex_lock(&data->write);
		printf("%li %i %s\n", time_function() - data->start, nbr, str);
		pthread_mutex_unlock(&data->write);
	}
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

int	eat_function(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left]);
	write_function(philo->nbr, data, "has taken a fork");
	if (data->philo_nbr == 1)
		return (ERROR);
	pthread_mutex_lock(&data->forks[philo->right]);
	write_function(philo->nbr, data, "has taken a fork");
	write_function(philo->nbr, data, "is eating");
	philo->last_eat = time_function();
	ft_usleep(data->time_to_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(&data->forks[philo->left]);
	pthread_mutex_unlock(&data->forks[philo->right]);
	return (0);
}
