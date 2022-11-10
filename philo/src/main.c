/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:03:58 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 15:43:32 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

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
	free_function(&data);
	return (0);
}
