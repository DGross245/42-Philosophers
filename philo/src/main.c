/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/11/01 18:16:49 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// zeiten stimmmt irgendwas nicht
// Nach tod wird weiter geschrieben
// number_of_philosophers time_to_die time_to_eat time_to_sleep [notepme]
//[argv1 is die anzahl der philos, mutexes und forks]
// INT_MAX UND INT_MIN checken (aktuele atoi geht es nicht)

int	main(int argc, char **argv)
{
	t_data	data;

	if (error_check(argc, argv) == ERROR)
	{
		printf("\033[0;31mERROR\033[0m\n");
		return (ERROR);
	}
	if (init_data(&data, argc, argv) == ERROR)
	{
		printf("\033[0;31mERROR\033[0m\n");
		return (ERROR);
	}
	if (create(&data) == ERROR)
	{
		printf("\033[0;31mERROR\033[0m\n");
		return (ERROR);
	}
	if (destroy(&data) == ERROR)
	{
		printf("\033[0;31mERROR\033[0m\n");
		return (ERROR);
	}
	return (0);
}
