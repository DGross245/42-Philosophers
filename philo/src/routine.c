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
	//int		cur_nbr;

	//cur_nbr = 1;
	philo = (t_philo *)data;
	//while(KP && philo->death != 1)
	//{
	//	eat_functin(philo, cur_nbr);
	//	sleep_function(philo, cur_nbr);
	//	think_function(philo, cur_nbr);
	//}
	return (NULL);
}

int	write_function(t_philo	*philo, char *str)
{
	pthread_mutex_lock(&philo->write);
	printf("%s\n", str);
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
	//pthread_mutex_lock(philo->fotk[i] != 0);
	//pthread_mutex_lock(philo->fotk[i + 1] != 0);
	write_function(philo, "has taken a fork");
	write_function(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	// timer für den philo reseten (time_to_die)
	return (0);
}
