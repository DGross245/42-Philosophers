/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/10/27 18:00:00 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// number_of_philosophers time_to_die time_to_eat time_to_sleep [notepme]
//[argv1 is die anzahl der philos, mutexes und forks]
// INT_MAX UND INT_MIN checken (aktuele atoi geht es nicht)
// nbr_philo % 2 soll time to eat wartem
// !!!!!! PHILO STRUCT KOMPLETT ÜBERARBEITEN DABEI ACHTEN KEINE DEPENDENSIES
// ZWISCHEN DEN STRUCTS ZU ERSTELLEN

int	main(int argc, char **argv)
{
	t_data	data;

	if (error_check(argc, argv) == ERROR)
		return (ERROR);
	init_philo(&data, argc, argv);
	if (create(&data) == ERROR)
		return (ERROR);
	if (destroy(&data) == ERROR)
		return (ERROR);
	return (0);
}
