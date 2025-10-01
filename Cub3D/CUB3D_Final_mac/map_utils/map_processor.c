/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:23:18 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_player_position(char direction, t_map_info *data, int x, int y)
{
	if (direction == 'N')
		data->angle_player = 270;
	else if (direction == 'S')
		data->angle_player = 90;
	else if (direction == 'W')
		data->angle_player = 180;
	else if (direction == 'E')
		data->angle_player = 0;
	data->x_player = x * 64;
	data->y_player = y * 64;
}

void	set_cell_value(char **map, t_map_info *data, int x, int y)
{
	char	cell;

	cell = map[y][x];
	if (cell == '1')
		data->map[y][x] = 1;
	else if (cell == ' ')
		data->map[y][x] = -1;
	else if (cell == 'd')
		data->map[y][x] = 500;
	else if (cell == '0')
		data->map[y][x] = 0;
	else if (cell == '#')
	{
		if (data->number_of_sprites < 15)
			data->number_of_sprites++;
		data->map[y][x] = -2;
	}
	else
	{
		free_map_memory(data->map, data->y_map_size);
		free_split(map);
		ft_printf("Error: Invalid map content\n");
		exit(1);
	}
}

void	validate_player_count(char **map, t_map_info *data, int *player_count)
{
	if (*player_count == 1)
	{
		free_map_memory(data->map, data->y_map_size);
		free_split(map);
		ft_printf("Error: Multiple players found\n");
		exit(1);
	}
	(*player_count)++;
}

void	process_cell(char **map, t_map_info *data, int x, int y)
{
	static int	player_count = 0;

	if (map[y][x] == 'N' || map[y][x] == 'S' ||
		map[y][x] == 'W' || map[y][x] == 'E')
	{
		validate_player_count(map, data, &player_count);
		data->map[y][x] = 0;
		set_player_position(map[y][x], data, x, y);
	}
	else
		set_cell_value(map, data, x, y);
}

void	process_map_grid(char **map, t_map_info *data)
{
	int			x;
	int			y;
	static int	total_players = 0;

	data->map = allocate_map_memory(data->y_map_size, data->x_map_size);
	y = 0;
	while (y < data->y_map_size)
	{
		x = 0;
		while (x < data->x_map_size)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'W' || map[y][x] == 'E')
				total_players++;
			process_cell(map, data, x, y);
			x++;
		}
		y++;
	}
	if (total_players == 0)
	{
		ft_printf("Error: No player found\n");
		exit(1);
	}
}
