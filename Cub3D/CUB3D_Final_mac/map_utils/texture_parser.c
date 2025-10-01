/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:09:31 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:25:58 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	assign_texture_path(char **tokens, t_map_info *data)
{
	char	*identifier;
	char	*path;

	identifier = tokens[0];
	path = tokens[1];
	if (!ft_strncmp(identifier, "NO", ft_strlen(identifier)))
		data->no_texture = ft_strdup(path);
	else if (!ft_strncmp(identifier, "SO", ft_strlen(identifier)))
		data->so_texture = ft_strdup(path);
	else if (!ft_strncmp(identifier, "EA", ft_strlen(identifier)))
		data->ea_texture = ft_strdup(path);
	else if (!ft_strncmp(identifier, "WE", ft_strlen(identifier)))
		data->we_texture = ft_strdup(path);
	else if (!ft_strncmp(identifier, "DO", ft_strlen(identifier)))
		data->do_texture = ft_strdup(path);
}

int	validate_texture_identifiers(char **identifiers)
{
	int	i;
	int	j;

	i = 0;
	while (identifiers[i])
	{
		j = i + 1;
		while (identifiers[j])
		{
			if (!ft_strncmp(identifiers[i], identifiers[j],
					ft_strlen(identifiers[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_config_tokens(char **tokens, char **valid_ids)
{
	if (count_array_elements(tokens) != 2)
	{
		free_split(tokens);
		return (0);
	}
	if (!find_in_array(valid_ids, tokens[0]))
	{
		free_split(tokens);
		return (0);
	}
	return (1);
}

int	process_config_line(char *line, t_map_info *data,
		char **valid_ids, char **found_ids)
{
	char		**tokens;
	char		*trimmed_line;
	static int	index = 0;

	trimmed_line = ft_strtrim(line, " \n");
	if (!ft_strlen(trimmed_line))
	{
		free(trimmed_line);
		return (1);
	}
	tokens = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!validate_config_tokens(tokens, valid_ids))
		return (0);
	found_ids[index++] = ft_strdup(tokens[0]);
	if (!parse_color_line(tokens, data))
	{
		free_split(tokens);
		return (0);
	}
	assign_texture_path(tokens, data);
	free_split(tokens);
	return (1);
}
