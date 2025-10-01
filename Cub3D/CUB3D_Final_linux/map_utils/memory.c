/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:13:23 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_map_memory(int **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	free_g_map(int **map, int tail)
{
	free_map_memory(map, tail);
}

int	**allocate_map_memory(int height, int width)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * width);
		if (!map[i])
		{
			free_map_memory(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}
