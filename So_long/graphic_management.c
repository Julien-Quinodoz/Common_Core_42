/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:36 by jquinodo          #+#    #+#             */
/*   Updated: 2024/12/02 14:04:58 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	free_map(game->map->vector);
	exit(0);
	return (0);
}

static void	init_img_to_mlx(t_game *game)
{
	int	width;
	int	height;

	game->img_ptr.floor = mlx_xpm_file_to_image(game->mlx, \
	"textures/floor.xpm", &width, &height);
	game->img_ptr.wall = mlx_xpm_file_to_image(game->mlx, \
	"textures/wall.xpm", &width, &height);
	game->img_ptr.collectible = mlx_xpm_file_to_image(game->mlx, \
	"textures/collectible.xpm", &width, &height);
	game->img_ptr.exit = mlx_xpm_file_to_image(game->mlx, \
	"textures/exit.xpm", &width, &height);
	if (!game->img_ptr.floor || !game->img_ptr.wall || \
		!game->img_ptr.collectible || !game->img_ptr.exit)
		print_error_message("Error: image cannot be initialized\n", game);
}

static void	put_image(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, (game->img_ptr).floor,
		x, y);
	if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).wall, x, y);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).collectible, x, y);
	else if (c == PLAYER)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).player, x, y);
	if (c == EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).exit, x, y);
}

void	put_image_to_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			put_image(game, game->map->vector[i][j], (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	create_game_interface(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		print_error_message("Error: mlx cannot initialized\n", game);
	game->mlx_window = mlx_new_window((game->mlx), (game->map->width * 64),
			(game->map->height * 64), "so_long");
	if (!(game->mlx_window))
		print_error_message("Error: mlx window cannot initialized\n", game);
	init_img_to_mlx(game);
	init_img_to_mlx_player(game);
	put_image_to_window(game);
	mlx_hook(game->mlx_window, KEY_PRESS, 0, key_handler, game);
	mlx_hook(game->mlx_window, CROSS, 0, exit_game, game);
	mlx_loop(game->mlx);
}
