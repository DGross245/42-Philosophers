/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/10/26 14:57:48 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// number_of_philosophers time_to_die time_to_eat time_to_sleep [notepme]
//[argv1 is die anzahl der philos, mutexes und forks]
// nur mit dem write mutex hat ein philo die erlaubnis zu printen
// philo[i] ist keine gut lösung (muss was anderes nehmne)
// INT_MAX UND INT_MIN checken (aktuele atoi geht es nicht)
// gabel struktur nochmal ändern bzw überarbeitten, irgendwas passt da nicht.
// nbr_philo % 2 soll time to eat wartem
// die philo nbr besser zuteilend da philo->philo->nbr nicht geht
// man müsste sowas wie philo->philo[i].nbr machen jedoch geht das nicht

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (error_check(argc, argv) == ERROR)
		return (ERROR);
	init_philo(&philo, argc, argv);
	if (create(&philo) == ERROR)
		return (ERROR);
	if (destroy(&philo) == ERROR)
		return (ERROR);
	return (0);
}
