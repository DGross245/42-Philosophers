/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:57:20 by dgross            #+#    #+#             */
/*   Updated: 2022/10/26 11:41:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> // malloc free
#include <stddef.h> // size_t

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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
