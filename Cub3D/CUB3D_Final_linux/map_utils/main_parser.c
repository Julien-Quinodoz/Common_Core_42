/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:23:18 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "get_next_line.h"

void	validate_file_extension(char *filename)
{
	if (!has_valid_extension(filename, ".cub"))
	{
		ft_printf("Error: File must have .cub extension\n");
		exit(1);
	}
}

void	validate_map_size(t_map_info *data, char **map)
{
	if (data->y_map_size > 42 || data->x_map_size > 42)
	{
		ft_printf("Error: Map too large (max 42x42)\n");
		free_split(map);
		exit(1);
	}
}

void	initialize_map_data(t_map_info *data)
{
	data->y_map_size = 0;
	data->x_map_size = 0;
	data->number_of_sprites = 0;
}

void	process_file_data(int fd, t_map_info *data)
{
	char	*config_data;
	char	*first_map_line;
	char	**raw_map;
	char	**normalized_map;

	config_data = read_config_section(fd, data);
	parse_configuration_data(ft_split(config_data, '\n'), data);
	free(config_data);
	first_map_line = skip_to_map_section(fd);
	if (!first_map_line)
	{
		ft_printf("Error: Empty map\n");
		exit(1);
	}
	raw_map = read_map_data(first_map_line, fd, data);
	validate_map_size(data, raw_map);
	normalized_map = normalize_map_grid(data, raw_map);
	validate_map_walls(normalized_map, data);
	process_map_grid(normalized_map, data);
	free_split(normalized_map);
}

int	lets_go(char **argv, t_map_info *data)
{
	int	fd;

	validate_file_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Cannot open file\n");
		exit(1);
	}
	initialize_map_data(data);
	process_file_data(fd, data);
	close(fd);
	return (0);
}
