/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:40:35 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 19:52:23 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*

**   Dessine le fond visuel de la scène, composé d’un ciel et d’un sol.

** Détail :
** - La première moitié verticale de l’écran (lignes 0 à 511) est utilisée pour
**   afficher le ciel, en appliquant un dégradé d’opacité descendant.
** - La seconde moitié (lignes 512 à 1023) représente le sol, avec un effet
**   d’éclaircissement progressif du bas vers le haut.

** Effet recherché :
**   Donner une sensation de profondeur et d’ambiance à la scène en
**   ajoutant un dégradé visuel simple mais esthétique.

** Paramètres :
** - vars : structure principale contenant les données de rendu et de couleur.

** Couleurs :
** - vars->map_info.c_color : couleur de base du ciel.
** - vars->map_info.f_color : couleur de base du sol.
*/
void	draw_sky_and_floor(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < 1024)
	{
		x = -1;
		while (++x < 512)
			mlx_put_pixel(vars->img, y, x, \
			create_color(vars->map_info.c_color.r, \
			vars->map_info.c_color.g, vars->map_info.c_color.b, 255 - x / 2));
		y++;
	}
	y = 0;
	while (y < 1024)
	{
		x = 511;
		while (++x < 1024)
			mlx_put_pixel(vars->img, y, x, \
			create_color(vars->map_info.f_color.r, \
			vars->map_info.f_color.g, vars->map_info.f_color.b, x / 2 - 255));
		y++;
	}
}

/*Parcourt tous les sprites du jeu, calcule leur position relative au joueur,
	et affiche seulement ceux qui sont dans le champ de vision.*/
void	draw_visible_sprites(t_vars *vars)
{
	static int	frame = 0;
	t_sp		sp;
	int			i;

	i = -1;
	while (++i < vars->numerof_sprite)
	{
		sp.sprite_ax = vars->sprites[i].x;
		sp.sprite_ay = vars->sprites[i].y;
		sp.dx = sp.sprite_ax - vars->player.x ;
		sp.dy = sp.sprite_ay - vars->player.y;
		sp.angle = atan2(sp.dy, sp.dx);
		if (sp.angle > vars->player.angle + M_PI)
			sp.angle -= 2 * M_PI;
		if (sp.angle < vars->player.angle - M_PI)
			sp.angle += 2 * M_PI;
		sp.angle_diff = sp.angle - vars->player.angle;
		sp.porce_angle = sp.angle_diff * 180 / M_PI;
		if (sp.angle_diff * 180 / M_PI <= 50
			&& sp.angle_diff * 180 / M_PI >= -50)
			draw_one_sprite_norm(vars, &sp, frame, i);
	}
	frame++;
	if (frame == 8)
		frame = 0;
}

/* Charge et affiche l'image de l'arme par défaut au démarrage du jeu.
 	texture = données brutes, image = objet affichable
	chemin texture -> png -> img -> affiche img -> delete texture */
void	draw_initial_gun(t_vars *vars)
{
	g_vars->weapon_texture = \
	mlx_load_png("./textures/weapon/Gun.png");
	if (!g_vars->weapon_texture)
	{
		printf("Error image Gun \n");
		exit(0);
	}
	g_vars->weapon_img = mlx_texture_to_image(g_vars->mlx, \
	g_vars->weapon_texture);
	mlx_image_to_window(vars->mlx, vars->weapon_img, 50, 257);
	mlx_delete_texture(g_vars->weapon_texture);
}

/* // Affiche le compteur de balles */
void	show_gun_magazine(t_vars *vars)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(vars->player.bullet);
	str = ft_strjoin(": ", tmp);
	mlx_image_to_window(vars->mlx, vars->ammo_img, 820, 25);
	mlx_delete_image(vars->mlx, vars->player.print_move);
	vars->player.print_move = mlx_put_string(vars->mlx, str, 900, 52);
	free(str);
	free(tmp);
}
