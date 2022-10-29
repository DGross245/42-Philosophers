/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:09:19 by dgross            #+#    #+#             */
/*   Updated: 2022/10/27 17:52:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	*routine(void *param)
{
	t_philo	*philo;
	t_data *data;

	philo = (t_philo *)param;
	data = (t_data *)philo->rules;
	printf("kekw\n");
	philo->times_eaten = time_funciton();
	while (data->death != 1)
	{
		printf("kekw\n");
		if (eat_function(philo, data) == ERROR)
			break ;
		if (sleep_function(philo, data) == ERROR)
			break ;
		if (think_function(philo, data) == ERROR)
			break ;
		data->death = 1;
	}
	return (NULL);
}

int	write_function(t_philo	*philo, t_data *data, char *str)
{
	pthread_mutex_lock(&data->write);
	printf("%i %i %s\n", 1, philo->nbr, str);
	pthread_mutex_unlock(&data->write);
	return (0);
}

int	sleep_function(t_philo	*philo, t_data *data)
{
	write_function(philo, data, "is eating");
	usleep(data->time_to_sleep * 1000);
	return (0);
}

int	think_function(t_philo	*philo, t_data *data)
{
	write_function(philo, data, "is thinking");
	return (0);
}

int	eat_function(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->nbr]);
	write_function(philo, data, "has taken a fork");
	pthread_mutex_lock(&data->forks[philo->nbr + 1]);
	write_function(philo, data, "has taken a fork");
	write_function(philo, data, "is eating");
	usleep(data->time_to_eat * 1000);
	philo->times_eaten++;
	philo->last_eat = time_funciton();
	pthread_mutex_lock(&data->forks[philo->nbr]);
	pthread_mutex_lock(&data->forks[philo->nbr + 1]);
	return (0);
}
