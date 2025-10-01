/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:06:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/13 10:49:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_map_info(t_map_info *data)
{
	g_vars->map_info.c_color.r = data->c_color.r;
	g_vars->map_info.c_color.g = data->c_color.g;
	g_vars->map_info.c_color.b = data->c_color.b;
	g_vars->map_info.f_color.b = data->f_color.b;
	g_vars->map_info.f_color.r = data->f_color.r;
	g_vars->map_info.f_color.g = data->f_color.g;
	g_vars->map_info.no_texture = data->no_texture;
	g_vars->map_info.so_texture = data->so_texture;
	g_vars->map_info.we_texture = data->we_texture;
	g_vars->map_info.ea_texture = data->ea_texture;
	g_vars->map_info.do_texture = data->do_texture;
}

/*
-> player.shoot = 0;	 ->  quand le joueur tire = 1
-> keyboard.show_map = 0; -> affiche la mini-map
-> angle_player * (M_PI / 180); -> transformation degré en radian
-> data->x_player + 32; -> +32 pour etre au milieu de la case de 64
-> 5 * cos(play.angle);->chaque frame, se déplacer de 5 pixels dans la direction
-> keyboard.cursor = 0; -> suprime le pointeur souris à 0 ou l affiche avec key F
*/
int	init_vars(t_map_info *data)
{
	g_vars = (t_vars *)malloc(sizeof(t_vars));
	if (!g_vars)
		return (0);
	g_vars->player.shoot = 0;
	g_vars->keyboard.show_map = 0;
	g_vars->player.bullet = 8;
	g_vars->window_info.height = 1024;
	g_vars->window_info.width = 1024;
	g_vars->map.map = data->map;
	g_vars->map.width = data->x_map_size;
	g_vars->map.height = data->y_map_size;
	g_vars->player.angle = data->angle_player * (M_PI / 180);
	g_vars->map_info.number_of_sprites = data->number_of_sprites;
	init_play_features(g_vars);
	g_vars->player.x = data->x_player + 32;
	g_vars->player.y = data->y_player + 32;
	g_vars->player.dx = 5 * cos(g_vars->player.angle);
	g_vars->player.dy = 5 * sin(g_vars->player.angle);
	g_vars->keyboard.cursor = 0;
	init_map_info(data);
	g_vars->start_time = time(NULL);
	g_vars->game_over = 0;
	g_vars->timer_img = NULL;
	return (1);
}

/* Cette fonction prépare les pointeurs pour gérer une collision horizontale
	dans un algorithme de raycasting.
Elle lie des pointeurs génériques (contenus dans la struct t_wall) aux bonnes
variables spécifiques à une collision horizontale (contenues dans t_ray_info).*/
void	set_initial_hwall_value(t_vars *vars, t_ray_info *ray, t_wall *wall)
{
	wall->x_val = &(ray->h_x);
	wall->y_val = &(ray->h_y);
	wall->dist = &(ray->h_dist);
	ft_initializer(vars, ray, wall);
}

/* Idem que hwall mais en vertiale */
void	set_initial_vwall_value(t_vars *vars, t_ray_info *ray, t_wall *wall)
{
	wall->x_val = &(ray->v_x);
	wall->y_val = &(ray->v_y);
	wall->dist = &(ray->v_dist);
	ft_initializer(vars, ray, wall);
}
