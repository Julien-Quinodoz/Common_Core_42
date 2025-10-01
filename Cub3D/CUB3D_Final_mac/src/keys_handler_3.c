/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:13 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 18:45:41 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*la touch F permet de basculer entre modes affichage curseur souris dans MLX42
	utile pour passer de mode "jeu" à "menu" ou pour reduire la fenêtre.*/
void	for_key_f(t_vars *vars)
{
	if (vars->keyboard.cursor)
		mlx_set_cursor_mode(vars->mlx, MLX_MOUSE_NORMAL);
	else
		mlx_set_cursor_mode(vars->mlx, MLX_MOUSE_DISABLED);
	if (vars->keyboard.cursor)
		vars->keyboard.cursor = 0;
	else
		vars->keyboard.cursor = 1;
}

/* touch TAB :Si show_map 1 (carte affichée), elle devient 0 (carte cachée)
	Sinon, elle devient 1 (carte affichée)*/
void	for_key_tab(t_vars *vars)
{
	if (vars->keyboard.show_map)
		vars->keyboard.show_map = 0;
	else
		vars->keyboard.show_map = 1;
}

/*La touche Espace permet au joueur d’alterner entre deux états sur
	la case juste devant lui, dans la direction où il regarde en calculant.
	Si la case vaut 500, elle est changée en -10. et inversément
	et ouverture de porte */
void	for_key_space(t_vars *vars)
{
	int	factx;
	int	facty;
	int	x;
	int	y;
	int	i;

	factx = (int)floor((vars->player.x) / 64);
	facty = (int)floor((vars->player.y) / 64);
	x = factx;
	y = facty;
	i = 1;
	while (x == factx && y == facty)
	{
		x = (int)floor((vars->player.x + (vars->player.dx * i)) / 64);
		y = (int)floor((vars->player.y + (vars->player.dy * i)) / 64);
		i++;
	}
	if (vars->map.map[y][x] == 500)
		vars->map.map[y][x] = -10;
	else if (vars->map.map[y][x] == -10)
		vars->map.map[y][x] = 500;
}

/*Cette fonction est un gestionnaire d'événements clavier
	Elle est appelée à chaque événement de pression de touche et elle
	gère plusieurs actions selon les touches actuellement pressées.
	--> Espace - R - TAB - ESCAPE - F  <--
	reload = 42; // déclanche l'animation de recharge de 42 frame
	show_gun_magazine(vars); // redessin : 8 */
void	key_press_handler_2(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	(void)keydata;
	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_SPACE))
		for_key_space(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_R))
	{
		if (!vars->player.reload && vars->player.bullet != 8)
		{
			vars->player.reload = 42;
			vars->player.bullet = 8;
			show_gun_magazine(vars);
		}
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
	{
		free_g_map(g_vars->map.map, g_vars->map.height);
		exit(0);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_TAB))
		for_key_tab(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_F))
		for_key_f(vars);
}
