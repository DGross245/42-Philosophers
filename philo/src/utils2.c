/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:02:31 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 15:00:41 by dgross           ###   ########.fr       */
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

	now = time_function();
	while ((time_function() - now) < time)
		usleep(200);
}
