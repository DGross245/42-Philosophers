/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:01:25 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 14:14:05 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	create(t_data *data)
{
	int	i;

	i = -1;
	data->forks = ft_malloc(sizeof(pthread_mutex_t) * (data->philo_nbr));
	if (data->forks == NULL)
		return (ERROR);
	while (++i < data->philo_nbr)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ERROR);
	create_mutex(data);
	pthread_mutex_lock(&data->write);
	i = -1;
	while (++i < data->philo_nbr)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
		&routine, &data->philo[i]) != 0)
			return (ERROR);
		data->philo[i].last_eat = time_function();
	}
	data->start = time_function();
	pthread_mutex_unlock(&data->write);
	death_function(data);
	return (0);
}

int	destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nbr)
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (ERROR);
	i = -1;
	while (++i < data->philo_nbr)
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			return (ERROR);
	if (pthread_mutex_destroy(&data->write) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&data->check) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&data->eat) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&data->dead) != 0)
		return (ERROR);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (max_check(argv) == ERROR)
		return (ERROR);
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start = 0;
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->death = 0;
	if (init_philo(data) == ERROR)
		return (ERROR);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philo = ft_malloc(sizeof(t_philo) * (data->philo_nbr));
	if (data->philo == NULL)
		return (ERROR);
	while (++i < data->philo_nbr - 1)
	{
		data->philo[i].nbr = i + 1;
		data->philo[i].data = data;
		data->philo[i].left = i;
		data->philo[i].right = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].times_eaten = 0;
	}
	data->philo[i].nbr = i + 1;
	data->philo[i].data = data;
	data->philo[i].left = i;
	data->philo[i].right = 0;
	data->philo[i].last_eat = 0;
	data->philo[i].times_eaten = 0;
	return (0);
}

int	max_check(char **argv)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 250)
		return (ERROR);
	while (argv[++i] != NULL)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (ERROR);
	}
	return (0);
}
