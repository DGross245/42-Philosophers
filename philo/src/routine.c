/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:09:19 by dgross            #+#    #+#             */
/*   Updated: 2022/10/25 10:53:55 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->philo->times_eaten = 0;
	while(philo->death != 1)
	{
		eat_functin(philo);
		sleep_function(philo);
		think_function(philo);
	}
	return (NULL);
}

int	write_function(t_philo	*philo, char *str)
{
	pthread_mutex_lock(&philo->write);
	printf("%i %i %s\n", /*time*/, philo->philo->nbr, str);
	pthread_mutex_unlock(&philo->write);
	return (0);
}

int	sleep_function(t_philo	*philo)
{
	write_function(philo, "is eating");
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

int	think_function(t_philo	*philo)
{
	write_function(philo, "is thinking");
	return (0);
}

int	eat_function(t_philo *philo)
{
	pthread_mutex_lock(philo->fotk[i] != 0);
	write_function(philo, "has taken a fork");
	pthread_mutex_lock(philo->fotk[i + 1] != 0);
	write_function(philo, "has taken a fork");
	write_function(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	philo->philo->times_eaten++;
	philo->philo->last_eat = // timeofday
	return (0);
}
