/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:07:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/10 15:43:48 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 5)
		return (ERROR);
	if (argc > 6)
		return (ERROR);
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
			if (ft_isdigit(argv[i][j++]) == 0)
				return (ERROR);
		i++;
	}
	return (0);
}

int	free_function(t_data *data)
{
	free(data->forks);
	free(data->philo);
	return (0);
}
