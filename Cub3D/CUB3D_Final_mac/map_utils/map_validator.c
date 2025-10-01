/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:26:01 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_validation_error(char **map)
{
	free_split(map);
	ft_printf("Error: Map is not properly enclosed by walls\n");
	exit(1);
}

int	is_boundary_position(int x, int y, t_map_info *data)
{
	if (y == 0 || x == 0)
		return (1);
	if (y + 1 >= data->y_map_size)
		return (1);
	if (x + 1 >= data->x_map_size)
		return (1);
	return (0);
}

int	has_adjacent_space(char **map, int x, int y, t_map_info *data)
{
	if (y > 0 && map[y - 1][x] == ' ')
		return (1);
	if (x > 0 && map[y][x - 1] == ' ')
		return (1);
	if (y + 1 < data->y_map_size && map[y + 1][x] == ' ')
		return (1);
	if (x + 1 < data->x_map_size && map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	validate_map_walls(char **map, t_map_info *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y_map_size)
	{
		x = 0;
		while (x < data->x_map_size)
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
			{
				if (is_boundary_position(x, y, data)
					|| has_adjacent_space(map, x, y, data))
					map_validation_error(map);
			}
			x++;
		}
		y++;
	}
	return (1);
}
