/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:05:56 by dgross            #+#    #+#             */
/*   Updated: 2022/10/23 17:36:35 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
typedef struct s_philo
{
	pthread_t	*thread_arr;
	pthread_mutex_t mutex;
}t_philo;

#endif