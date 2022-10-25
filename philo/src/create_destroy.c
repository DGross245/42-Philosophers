/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:01:25 by dgross            #+#    #+#             */
/*   Updated: 2022/10/25 08:06:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	create(t_philo *philo)
{
	int	i;

	i = -1;
	philo->philo = ft_malloc(sizeof(t_data) * (philo->philo_nbr));
	while (++i < philo->philo_nbr)
		if (pthread_create(&philo->philo[i].thread, NULL, &routine, NULL) != 0)
			return (-1);
	i = -1;
	philo->forks = ft_malloc(sizeof(pthread_mutex_t) * (philo->philo_nbr));
	while (++i < philo->philo_nbr)
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			return (-1);
	if (pthread_mutex_init(&philo->write, NULL) != 0)
		return (-1);
	return (0);
}

int	destroy(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_nbr)
		if (pthread_join(philo->philo[i].thread, NULL) != 0)
			return (-1);
	i = -1;
	while (++i < philo->philo_nbr)
		if (pthread_mutex_destroy(&philo->forks[i]) != 0)
			return (-1);
	if (pthread_mutex_destroy(&philo->write) != 0)
		return (-1);
	return (0);
}

void	init_philo(t_philo	*philo, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < philo->philo_nbr)
		philo->philo[i].nbr = i + 1;
	philo->philo_nbr = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->max_eat = ft_atoi(argv[5]);
	else
		philo->max_eat = -1;
}
