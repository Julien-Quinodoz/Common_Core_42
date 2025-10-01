/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:09:37 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:26:00 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_valid_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_rgb_value(char *str)
{
	int	i;

	if (!str || ft_strlen(str) > 3)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!is_valid_number(str[i]))
			return (0);
		i++;
	}
	return (ft_atoi(str) <= 255);
}

int	count_array_elements(char **arr)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int	find_in_array(char **arr, char *target)
{
	int	i;

	if (!arr || !target)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(arr[i], target, ft_strlen(target)))
			return (1);
		i++;
	}
	return (0);
}
