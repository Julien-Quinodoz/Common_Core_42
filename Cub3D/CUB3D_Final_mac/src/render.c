/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:06:02 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 19:38:21 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Paramètres :
	button : quel bouton de souris (0 = clic gauche)
	action : type d'action (1 = pression du bouton)
	mods : modificateurs clavier  (non utilisé ici, d'où le (void)mods)
	param : données du jeu castées vers t_vars
	============================================
	vars->player.shoot = 8; -> déclenche l'animation de tir (durée de 8 frames)
		show_gun_magazine(vars); -> met à jour l'affichage des munitions
si non
	 -> recharge le chargeur à 8 balles
	->  vars->player.reload -> lance l'animation de rechargement (42 frames )
	show_gun_magazine(vars);: met à jour l'affichage des munitions

	 */
void	mouse_click(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_vars	*vars;

	(void)mods;
	vars = (t_vars *)param;
	if (button == 0 && action == 1 && vars->player.bullet
		&& !vars->player.reload)
	{
		vars->player.bullet--;
		vars->player.shoot = 8;
		show_gun_magazine(vars);
	}
	else if (button == 0 && action == 1 && !vars->player.bullet
		&& !vars->player.reload)
	{
		vars->player.bullet = 8;
		vars->player.reload = 42;
		show_gun_magazine(vars);
	}
}

void	check_textures(void)
{
	if (!g_vars->so_wall_texture || !g_vars->ea_wall_texture
		|| !g_vars->we_wall_texture || !g_vars->no_wall_texture
		|| !g_vars->door_texture || !g_vars->door_texture
		|| !g_vars->ammo_texture || !g_vars->ammo_img)
	{
		free_g_map(g_vars->map.map, g_vars->map.height);
		exit(0);
	}
}

/*
  ->  ammo fait partie de l'interface utilisateur (UI/HUD)
  */
void	initialize_textures(void)
{
	g_vars->player.reload = 0;
	g_vars->so_wall_texture = mlx_load_png(g_vars->map_info.so_texture);
	g_vars->ea_wall_texture = mlx_load_png(g_vars->map_info.we_texture);
	g_vars->we_wall_texture = mlx_load_png(g_vars->map_info.ea_texture);
	g_vars->no_wall_texture = mlx_load_png(g_vars->map_info.no_texture);
	g_vars->door_texture = mlx_load_png(g_vars->map_info.do_texture);
	g_vars->ammo_texture = mlx_load_png("./textures/weapon/bullet.png");
	g_vars->ammo_img = mlx_texture_to_image(g_vars->mlx, g_vars->ammo_texture);
	check_textures();
	free(g_vars->map_info.no_texture);
	free(g_vars->map_info.so_texture);
	free(g_vars->map_info.we_texture);
	free(g_vars->map_info.ea_texture);
	free(g_vars->map_info.do_texture);
}

/* configure tous les contrôles et lance la boucle principale du jeu.
--> mlx_loop_hook(g_vars->mlx, &loop_func, g_vars);  Enregistre la fonction qui
sera appellée (pointeur sur loop_func) en continu (chaque 5 frame) dans mlx loop

-->	mlx_loop(g_vars->mlx); DÉMARRE la boucle BLOQUANTE, reste ici jusqu'a la fin)
*/
void	my_mlx_hooks(t_vars *g_vars)
{
	if (g_vars->keyboard.cursor)
		mlx_set_cursor_mode(g_vars->mlx, MLX_MOUSE_NORMAL);
	else
		mlx_set_cursor_mode(g_vars->mlx, MLX_MOUSE_DISABLED);
	mlx_key_hook(g_vars->mlx, (mlx_keyfunc)key_press_handler_2, g_vars);
	mlx_cursor_hook(g_vars->mlx, (mlx_cursorfunc)mouse_handler, g_vars);
	mlx_mouse_hook(g_vars->mlx, (mlx_mousefunc)mouse_click, g_vars);
	mlx_image_to_window(g_vars->mlx, g_vars->img, 0, 0);
	mlx_loop_hook(g_vars->mlx, &loop_func, g_vars);
	show_gun_magazine(g_vars);
	mlx_loop(g_vars->mlx);
}

/*Une fenêtre "cub3D" s'affiche
Le jeu est prêt à recevoir les inputs clavier/souris
La boucle de jeu principale tourne en continu
L'utilisateur peut jouer !
======================================================
mlx_new_image(g_vars->mlx, width, height);
--> Crée une image en mémoire de 1024x1024 pixels où tu vas dessiner
	:Les murs du raycasting - L'interface utilisateur  - Les effets visuels

redraw(g_vars);			 // Dessine la première frame du jeu
my_mlx_hooks(g_vars);		// Configure les contrôles et lance la boucle de jeu

*/
void	render_window(t_vars *g_vars)
{
	int	width;
	int	height;

	width = g_vars->window_info.width;
	height = g_vars->window_info.height;
	g_vars->mlx = mlx_init(width, height, "cub3D", 1);
	if (!g_vars->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(1);
	}
	mlx_set_window_limit(g_vars->mlx, width - 200, height - 200, width, height);
	g_vars->img = mlx_new_image(g_vars->mlx, width, height);
	initialize_textures();
	redraw(g_vars);
	my_mlx_hooks(g_vars);
}
