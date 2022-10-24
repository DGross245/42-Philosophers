/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/10/24 11:02:15 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

// thread ist sowaas wie ein prozess nur teilen sich alle die gleichen datan und erstellen keine kopie
// mutex ist einfach ein schutz, damit threads nicht sachen gleichzeitg etwas machen sonden warten bis sie dürfen

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
//[argv1 is die anzahl der philos, mutexes und forks]
int		destroy(t_philo *philo);
int		create(t_philo *philo);
void	*routine(void *data);
void	*ft_malloc(size_t size);
int		ft_atoi(const char	*str);
void	ft_bzero(void *s, size_t n);
void	init_philo(t_philo	*philo, int argc, char **argv);
int		error_check(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (error_check(argc, argv) == -1)
	{
		printf("error\n");
		return (-1);
	}
	init_philo(&philo, argc, argv);
	create(&philo);
	destroy(&philo);
	return (0);
}

int error_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc < 5)
		return (-1);
	if (argc > 6)
		return (-1);
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;	
		}
		i++;
	}
	return (0);
}

void init_philo(t_philo	*philo, int argc, char **argv)
{
	//int i;

	//i = 0;
	
	//while (++i < philo->philo_nbr + 1)
	//	philo->philo[i].nbr = i;
	philo->philo_nbr = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->max_eat = ft_atoi(argv[5]);
	else
		philo->max_eat = -1;
}

int create(t_philo *philo)
{
	int	i;

	i = -1;
	philo->thread_arr = ft_malloc(sizeof(pthread_t) * (philo->philo_nbr));
	while (++i < philo->philo_nbr)
		if (pthread_create(&philo->thread_arr[i], NULL, &routine, NULL) != 0)
			return (2);
	i = -1;
	philo->mutex_arr = ft_malloc(sizeof(pthread_mutex_t) * (philo->philo_nbr));
	while (++i < philo->philo_nbr)
		if (pthread_mutex_init(&philo->mutex_arr[i], NULL) != 0)
			return (3);
	return (0);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	// take folk 
	// eat
	// sleep
	// think
	// repeat
	return(NULL);
}

int destroy(t_philo *philo)
{
	int	i;

	i = -1;
	while (philo->thread_arr[++i] != NULL)
		if (pthread_join(philo->thread_arr[i], NULL) != 0)
			return (4);
	i = -1;
	while (++i < philo->philo_nbr)
		if (pthread_mutex_destroy(&philo->mutex_arr[i]) != 0)
			return (5);
	return (0);
}
