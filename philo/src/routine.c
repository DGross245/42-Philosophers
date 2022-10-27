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

void	*routine(void *philo)
{
	t_data	*philo;

	philo = (t_philo *)philo;
	philo->times_eaten = time_funciton();
	while (philo->death != 1)
	{
		if (eat_function(philo) == ERROR)
			break ;
		if (sleep_function(philo) == ERROR)
			break ;
		if (think_function(philo) == ERROR)
			break ;
		philo->death = 1;
	}
	return (NULL);
}

int	write_function(t_philo	*philo, char *str)
{
	pthread_mutex_lock(&philo->write);
	printf("%i %i %s\n", 1, philo->philo->nbr, str);
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
	pthread_mutex_lock(&philo->philo[i].nbr]);
	write_function(philo, "has taken a fork");
	pthread_mutex_lock(&philo->forks[philo->philo[0].nbr + 1]);
	write_function(philo, "has taken a fork");
	write_function(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	philo->philo->times_eaten++;
	philo->philo->last_eat = time_funciton();
	pthread_mutex_lock(&philo->forks[philo->philo[0].nbr]);
	pthread_mutex_lock(&philo->forks[philo->philo[0].nbr + 1]);
	return (0);
}
