/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:09:22 by rodrigo           #+#    #+#             */
/*   Updated: 2025/06/16 13:25:56 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*trim_whitespace(char *str)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] && (str[start] == ' ' || str[start] == '\n'))
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && (str[end] == ' ' || str[end] == '\n'))
		end--;
	result = malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = str[start++];
	result[i] = '\0';
	free(str);
	return (result);
}

int	has_valid_extension(char *filename, char *extension)
{
	int	len;
	int	ext_len;

	if (!filename || !extension)
		return (0);
	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (len < ext_len)
		return (0);
	return (!ft_strncmp(filename + len - ext_len, extension, ext_len + 1));
}
