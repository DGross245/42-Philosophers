/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:09:19 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 16:02:14 by dgross           ###   ########.fr       */
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
	pthread_mutex_lock(&data->dead);
	while (data->death != 1 && philo->times_eaten != data->max_eat)
	{
		pthread_mutex_unlock(&data->dead);
		if (eat_function(philo, data) == ERROR)
			break ;
		if (data->max_eat != philo->times_eaten)
		{
			if (sleep_function(philo, data) == ERROR)
				break ;
			if (think_function(philo, data) == ERROR)
				break ;
		}
		pthread_mutex_lock(&data->dead);
	}
	pthread_mutex_unlock(&data->dead);
	return (NULL);
}
