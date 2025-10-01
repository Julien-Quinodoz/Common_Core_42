/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management_player.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:36 by jquinodo          #+#    #+#             */
/*   Updated: 2024/12/02 14:07:03 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_img_to_mlx_player(t_game *game)
{
	int	width;
	int	height;

	game->img_ptr.player_up = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_up.xpm", &width, &height);
	game->img_ptr.player_down = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_down.xpm", &width, &height);
	game->img_ptr.player_left = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_left.xpm", &width, &height);
	game->img_ptr.player_right = mlx_xpm_file_to_image(game->mlx, \
	"textures/player_right.xpm", &width, &height);
	game->img_ptr.player = mlx_xpm_file_to_image(game->mlx, \
	"textures/player.xpm", &width, &height);
	if (!game->img_ptr.player_up || !game->img_ptr.player_down || \
		!game->img_ptr.player_left || !game->img_ptr.player_right)
		print_error_message("Error: image cannot be initialized\n", game);
}
