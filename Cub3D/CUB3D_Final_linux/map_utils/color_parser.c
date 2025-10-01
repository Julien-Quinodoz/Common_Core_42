/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:07:57 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:18:50 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_rgb_color(t_map_info *data, char *value, int index, char type)
{
	int	color_value;

	color_value = ft_atoi(value);
	if (type == 'F')
	{
		if (index == 0)
			data->f_color.r = color_value;
		else if (index == 1)
			data->f_color.g = color_value;
		else if (index == 2)
			data->f_color.b = color_value;
	}
	else if (type == 'C')
	{
		if (index == 0)
			data->c_color.r = color_value;
		else if (index == 1)
			data->c_color.g = color_value;
		else if (index == 2)
			data->c_color.b = color_value;
	}
}

int	validate_and_set_color(t_map_info *data, char **rgb_values, char type)
{
	int	i;

	if (count_array_elements(rgb_values) != 3)
		return (0);
	i = 0;
	while (rgb_values[i])
	{
		if (!is_valid_rgb_value(rgb_values[i]))
		{
			free_split(rgb_values);
			return (0);
		}
		set_rgb_color(data, rgb_values[i], i, type);
		i++;
	}
	return (1);
}

int	parse_color_line(char **tokens, t_map_info *data)
{
	char	**rgb_values;
	char	*identifier;
	char	*values;
	int		result;

	if (count_array_elements(tokens) != 2)
		return (0);
	identifier = tokens[0];
	values = tokens[1];
	if (!ft_strncmp(identifier, "F", ft_strlen(identifier))
		|| !ft_strncmp(identifier, "C", ft_strlen(identifier)))
	{
		rgb_values = ft_split(values, ',');
		result = validate_and_set_color(data, rgb_values, identifier[0]);
		free_split(rgb_values);
		return (result);
	}
	return (1);
}
