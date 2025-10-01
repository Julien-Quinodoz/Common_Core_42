/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:47:51 by jquinodo          #+#    #+#             */
/*   Updated: 2024/12/02 13:09:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		exit(0);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_error_message(char *error_message, t_game *game)
{
	ft_printf(error_message);
	free_map(game->map->vector);
	exit(EXIT_FAILURE);
}

void	print_error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}
