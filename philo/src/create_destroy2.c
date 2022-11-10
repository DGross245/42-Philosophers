/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:08:16 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 11:09:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	create_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->check, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->eat, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->dead, NULL) != 0)
		return (ERROR);
	return (0);
}
