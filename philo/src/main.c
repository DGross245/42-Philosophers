/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/10/25 08:16:25 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// thread ist sowaas wie ein prozess nur teilen sich alle die gleichen datan und erstellen keine kopie
// mutex ist einfach ein schutz, damit threads nicht sachen gleichzeitg etwas machen sonden warten bis sie dürfen

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
//[argv1 is die anzahl der philos, mutexes und forks]
// nur mit dem write mutex hat ein philo die erlaubnis zu printen

// mallocs protekten und vllt auch alle pthread funktionen und funktionen wo ich -1 returne
// threads als letztes erstellen weil sie dann direkt in die loop gehen und nicht den rest machen
// input wie bei push_swap check bzw einfach funktion kopieren sollte gehen :D
// write function = mutex write locken printen wieder unlocken
// sleep = printen und dann usleop(time_to_sleep)? i guess
// eaten = linke rechte gabel nehmen printen(frage ist ob ob man für beie forks printen muss) print eat usleep(time_to_eat) ? beide wieder ablegen
// think = entweder nur printen oder noch usleep
// time = mit timeofday funktion irgendwie was machen aber weiss noch nicht was aber mal gucken
// dead = check if last time eat mit der vergangenen zeit grösser ist als time_to_die (wann man abfragen soll kp vllt noch allen 3 abläufen ?)
// weg finden nicht alle gleichzeitig laufen zu lassen, da dadurch die philos sich die gabeln klauen würden
int	main(int argc, char **argv)
{
	t_philo	philo;

	if (error_check(argc, argv) == -1)
		return (-1);
	init_philo(&philo, argc, argv);
	if (create(&philo) == -1)
		return (-1);
	destroy(&philo);
	return (0);
}
