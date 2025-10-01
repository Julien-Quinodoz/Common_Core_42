/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/17 17:13:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "get_next_line.h"

int	count_config_lines(char *line)
{
	char	*trimmed;
	int		length;

	trimmed = ft_strtrim(line, "\n ");
	length = ft_strlen(trimmed);
	free(trimmed);
	return (length > 2);
}

char	*read_config_section(int fd, t_map_info *data)
{
	char	*line;
	char	*config_data;
	int		config_lines;

	(void)data;
	config_lines = 0;
	config_data = ft_strdup("");
	line = get_next_line(fd);
	while (line && config_lines < 7)
	{
		if (count_config_lines(line))
			config_lines++;
		config_data = ft_strjoin_gnl(config_data, line);
		free(line);
		line = NULL;
		if (config_lines == 7)
			break ;
		line = get_next_line(fd);
	}
	return (config_data);
}

char	*skip_to_map_section(int fd)
{
	char	*line;
	char	*trimmed;
	int		length;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n ");
		length = ft_strlen(trimmed);
		free(trimmed);
		if (length > 2)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	get_max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
