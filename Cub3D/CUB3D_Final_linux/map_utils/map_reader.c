/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:26:03 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "get_next_line.h"

int	validate_map_line_length(char *line, char *data, int should_stop)
{
	int	length;

	length = ft_strlen(line);
	if (line[length - 1] == '\n')
		length--;
	if (should_stop || !length)
	{
		ft_printf("Error: Invalid map line length\n");
		free(line);
		free(data);
		exit(1);
	}
	return (length);
}

char	**read_map_data(char *first_line, int fd, t_map_info *data)
{
	char	*map_data;
	char	*line;
	int		should_stop;
	int		line_length;
	char	**result;

	should_stop = 0;
	map_data = ft_strdup("");
	line = first_line;
	while (line)
	{
		line_length = validate_map_line_length(line, map_data, should_stop);
		if (line_length < 2)
			should_stop = 1;
		data->x_map_size = get_max_value(line_length, data->x_map_size);
		map_data = ft_strjoin_gnl(map_data, line);
		free(line);
		line = get_next_line(fd);
		data->y_map_size++;
	}
	result = ft_split(map_data, '\n');
	free(map_data);
	return (result);
}

void	copy_and_pad_line(char **normalized_map, char **raw_map,
		t_map_info *data, int i)
{
	int	j;

	normalized_map[i] = malloc(data->x_map_size + 1);
	if (!normalized_map[i])
		return ;
	j = 0;
	while (raw_map[i][j])
	{
		normalized_map[i][j] = raw_map[i][j];
		j++;
	}
	while (j < data->x_map_size)
	{
		normalized_map[i][j] = ' ';
		j++;
	}
	normalized_map[i][j] = '\0';
	free(raw_map[i]);
}

char	**normalize_map_grid(t_map_info *data, char **raw_map)
{
	char	**normalized_map;
	int		i;

	normalized_map = malloc(sizeof(char *) * (data->y_map_size + 1));
	if (!normalized_map)
		return (NULL);
	i = 0;
	while (raw_map[i])
	{
		copy_and_pad_line(normalized_map, raw_map, data, i);
		i++;
	}
	normalized_map[i] = NULL;
	free(raw_map);
	return (normalized_map);
}
