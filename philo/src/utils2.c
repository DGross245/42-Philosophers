/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:41:22 by dna               #+#    #+#             */
/*   Updated: 2022/11/08 14:39:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	entrance_blocker(t_philo *philo)
{
	ft_usleep(philo->data->time_to_eat);
}

void	ft_usleep(long time)
{
	long	now;

	now = 0;
	now = time_function();
	while ((time_function() - now) < time)
		usleep(200);
}
