/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:15:03 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:05:57 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if (c != '\t' && c != '\n' && c != '\v' \
		&& c != '\f' && c != '\r' && c != ' ')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	sum;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	sum = 0;
	while (ft_isdigit(str[i]))
	{
		sum = sum * 10 + (str[i] - '0');
		if (sum < 0)
			return ((sign != -1) * -1);
		i++;
	}
	return (sum * sign);
}
