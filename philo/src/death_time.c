/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:15:00 by dgross            #+#    #+#             */
/*   Updated: 2022/11/01 11:47:31 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

long	time_function(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

void	death_function(t_data *data)
{
	int		i;
	long	time;

	time = 0;
	while (1)
	{
		i = -1;
		while (++i < data->philo_nbr && data->death != 1)
		{
			time = get_time_dif(data->philo[i].last_eat, data);
			if (time >= data->time_to_die)
			{
				write_function(data->philo[i].nbr, data, "\033[0;31mis dead");
				data->death = 1;
				break ;
			}		
		}
		if (data->death == 1)
			break ;
		if (data->max_eat != -1 && food_checker(data) == data->philo_nbr)
			break ;
	}
}

long	get_time_dif(long time, t_data *data)
{
	if (time > 0)
		return (time_function() - time);
	else
		time = time_function() - data->start;
	return (time);
}

int	food_checker(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (data->philo[i].times_eaten != data->max_eat)
			return (i);
		i++;
	}
	return (i);
}
