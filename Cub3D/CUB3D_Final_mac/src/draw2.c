/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:20:19 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/13 17:47:08 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* dessine une Croix de 17 pixels viseur au centre */
void	draw_aim(t_vars *vars)
{
	t_line	line;

	line.x0 = 512;
	line.y0 = 504;
	line.x1 = 512;
	line.y1 = 521;
	line.map_height = vars->img->height;
	line.map_width = vars->img->width;
	line.color = create_color(0, 255, 0, 255);
	put_line(&line);
	line.x0 = 504;
	line.y0 = 512;
	line.x1 = 521;
	line.y1 = 512;
	put_line(&line);
}

/* Affiche l'animation de tir frame par frame, puis passe à la suivante.*/
void	redraw_shoot(t_vars *vars, char *tmp, char *str)
{
	tmp = ft_itoa(9 - g_vars->player.shoot);
	str = ft_strjoin("./textures/weapon/Gun_shoot_", tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ".png");
	g_vars->weapon_texture = mlx_load_png(str);
	g_vars->weapon_img = mlx_texture_to_image(g_vars->mlx, \
	g_vars->weapon_texture);
	mlx_image_to_window(vars->mlx, vars->weapon_img, 50, 257);
	mlx_delete_texture(g_vars->weapon_texture);
	free(str);
	free(tmp);
	g_vars->player.shoot--;
}

/*Animation de recharge
->  reload = 42 ; donc 42 frame, animation reload
-> Charge la texture Reload_Rxxx.png
-> Affiche sur à la position (50,257)
->  redessine frame par frame 42 - 41- 40 -39 - ...
-> player.shoot = 0; -> Empêche de tirer pendant le rechargement
*/
void	redraw_reload(t_vars *vars, char *tmp, char *str)
{
	tmp = ft_itoa(43 - g_vars->player.reload);
	str = ft_strjoin("./textures/weapon/Reload_R", tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ".png");
	free(tmp);
	g_vars->weapon_texture = mlx_load_png(str);
	g_vars->weapon_img = mlx_texture_to_image(g_vars->mlx, \
	g_vars->weapon_texture);
	mlx_image_to_window(vars->mlx, vars->weapon_img, 50, 257);
	mlx_delete_texture(g_vars->weapon_texture);
	free(str);
	g_vars->player.reload--;
	vars->player.shoot = 0;
}

/* BOUCLE redraw est appelée automatiquement et en BOUCLE par la MLX,
	ce qui créer les animations comme shoot*/
void	redraw(t_vars *vars)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = NULL;
	(void)str;
	(void)tmp;
	key_press_handler_1(vars);
	mlx_delete_image(g_vars->mlx, g_vars->weapon_img);
	draw_sky_and_floor(vars);
	draw_ray(vars);
	draw_visible_sprites(vars);
	if (vars->keyboard.show_map)
	{
		draw_player_on_minimap(vars);
		draw_mini_map(vars);
	}
	if (vars->player.reload)
		redraw_reload(vars, tmp, str);
	else if (vars->player.shoot)
		redraw_shoot(vars, tmp, str);
	else
		draw_initial_gun(vars);
	draw_aim(vars);
	play_action(vars);
}

/*
Calcule la portion précise de la texture à afficher pour un mur en fonction
de l’intersection du rayon avec le mur (verticale ou horizontale) et prépare
les paramètres nécessaires pour le dessin.
Choisit ensuite la texture appropriée (mur ou porte) et appelle la fonction
de rendu draw_it pour afficher le mur avec la bonne texture et hauteur.*/
void	draw_wall(t_vars *vars, t_ray_info	ray, double lineH, int hororver)
{
	t_draw_value	info;

	if (hororver == 1)
		info.porcentsage = ray.ry / 64;
	if (hororver == 0)
		info.porcentsage = ray.rx / 64;
	info.porcentsage -= (int)info.porcentsage;
	info.x1 = ray.ray * 2 + 2;
	lineH = draw_wall_data(&info, lineH);
	if (vars->map.map[(int)floor(ray.ry / 64)][(int)floor(ray.rx / 64)] == 500)
		info.imgtxet = vars->door_texture;
	else if (hororver == 0)
		decide_vertical_textures(vars, &info, ray.ry);
	else if (hororver == 1)
		decide_horizontal_textures(vars, &info, ray.rx);
	info.theline = (int)(info.porcentsage * 512);
	info.theline *= 4;
	info.g = (float)512 / info.k;
	info.rl = 0;
	info.in = 0;
	draw_it(vars, &info, lineH);
}
