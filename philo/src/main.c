/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/10/23 17:42:03 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

// thread ist sowaas wie ein prozess nur teilen sich alle die gleichen datan und erstellen keine kopie
// mutex ist einfach ein schutz, damit threads nicht sachen gleichzeitg etwas machen sonden warten bis sie dürfen

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// vllt. zu einer anderen lösung wechseln als atoi um char *philo_nbr in ein int zu machen (vllt. auch drin lassen für zahlen check idk)

// threads gehen nicht in idk_yet rein und führen nicht printf aus!
void kill_thread(t_philo *philo);
void create_thread(char *philo_nbr, t_philo *philo);
void *idk_yet();
void *ft_malloc(size_t size);
int	ft_atoi(const char	*str);
void ft_bzero(void *s, size_t n);

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5)
		return (-1);
	pthread_mutex_init(&philo.mutex, NULL);
	create_thread(argv[1], &philo);
	kill_thread(&philo);
	pthread_mutex_destroy(&philo.mutex);
	return (0);
}

void create_thread(char *philo_nbr, t_philo *philo)
{
	int	i;

	i = -1;
	philo->thread_arr = ft_malloc(sizeof(pthread_t) * ft_atoi(philo_nbr));
	while (philo->thread_arr[++i] != NULL)
	{ 
		pthread_create(&philo->thread_arr[i], NULL, &idk_yet, NULL);
	}
}

void *idk_yet(void *kek)
{
	t_philo *philo;

	philo = (t_philo *)kek;
	printf("thread done\n");
	return(kek);
}

void kill_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (philo->thread_arr[++i] != NULL)
	{
		if (pthread_join(philo->thread_arr[i], NULL) != 0)
			return ;
	}
}

#include <stdlib.h> // malloc free

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	else
	{
		free(ptr);
		exit(1);
	}
	return (ptr);
}

static int	isnumber(const char *str, int i, int sign, long int result1)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result1 * sign > 2147483647)
			return (-1);
		if (result1 * sign < -2147483648)
			return (0);
		result1 = 10 * result1 + (str[i] - '0');
		i++;
	}
	return (result1);
}

int	ft_atoi(const char	*str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	result = isnumber(str, i, sign, result) * sign;
	return (result);
}

#include <stddef.h> // size_t

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	c = 0;
	ptr = s;
	while (n)
	{
		*ptr = c;
		ptr++;
		n--;
	}
}