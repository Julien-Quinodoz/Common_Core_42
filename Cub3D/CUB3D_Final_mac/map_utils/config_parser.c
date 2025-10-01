/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:26:08 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	validate_config_line_count(char **config_lines)
{
	int		count;
	int		valid_lines;
	char	**tokens;

	count = 0;
	valid_lines = 0;
	while (config_lines[count])
	{
		tokens = ft_split(config_lines[count], ' ');
		if (count_array_elements(tokens) > 1)
			valid_lines++;
		free_split(tokens);
		count++;
	}
	if (valid_lines != 7)
	{
		ft_printf("Error: Invalid configuration data\n");
		free_split(config_lines);
		exit(1);
	}
	return (1);
}

void	init_config_parsing(char **found_ids, char ***valid_ids,
		char *valid_identifiers)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		found_ids[i] = NULL;
		i++;
	}
	*valid_ids = ft_split(valid_identifiers, ' ');
}

int	process_config_lines(char **config_lines, t_map_info *data,
		char **valid_ids, char **found_ids)
{
	int	i;

	i = 0;
	while (config_lines[i])
	{
		if (!process_config_line(config_lines[i], data, valid_ids, found_ids))
		{
			ft_printf("Error: Invalid configuration line\n");
			free_split(valid_ids);
			free_split(found_ids);
			free_split(config_lines);
			exit(1);
		}
		i++;
	}
	return (1);
}

void	parse_configuration_data(char **config_lines, t_map_info *data)
{
	char	*valid_identifiers;
	char	**valid_ids;
	char	**found_ids;

	valid_identifiers = "NO SO WE EA DO F C";
	validate_config_line_count(config_lines);
	found_ids = malloc(sizeof(char *) * 8);
	if (!found_ids)
		exit(1);
	init_config_parsing(found_ids, &valid_ids, valid_identifiers);
	process_config_lines(config_lines, data, valid_ids, found_ids);
	if (!validate_texture_identifiers(found_ids))
	{
		ft_printf("Error: Duplicate texture identifiers\n");
		exit(1);
	}
	free_split(valid_ids);
	free_split(found_ids);
	free_split(config_lines);
}
