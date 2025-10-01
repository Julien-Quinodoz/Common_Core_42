/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:32:35 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 18:28:29 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Dessine la MINI map*/
void	draw_mini_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map.height)
	{
		x = -1;
		while (++x < vars->map.width)
			draw_tile(vars, y, x);
	}
}

/*Dessine les tuiles de la mini-map*/
void	draw_tile(t_vars *vars, int y, int x)
{
	int			i;
	int			j;
	uint32_t	c_w;
	uint32_t	c_g;
	uint32_t	c_b;

	i = -1;
	c_w = create_color(50, 50, 50, 255);
	c_g = create_color(100, 169, 213, 160);
	c_b = create_color(60, 179, 113, 255);
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
		{
			if (vars->map.map[y][x] == 500)
				mlx_put_pixel(vars->img, (16 * x) + i, (16 * y) + j, c_b);
			else if (vars->map.map[y][x] > 0)
				mlx_put_pixel(vars->img, (16 * x) + i, (16 * y) + j, c_g);
			if ((j == 15 || i == 15))
				mlx_put_pixel(vars->img, (16 * x) + i, (16 * y) + j, c_w);
		}
	}
}

void	draw_player_on_minimap(t_vars *vars)
{
	t_line	line;
	int		radius;
	int		x;
	int		y;

	x = 0;
	radius = 4;
	line.x0 = (vars->player.x * 16) / 64;
	line.y0 = (vars->player.y * 16) / 64;
	while (x < 16 * vars->map.width)
	{
		y = 0;
		while (y < 16 * vars->map.height)
		{
			if ((x - line.x0) * (x - line.x0) + (y - line.y0) \
				* (y - line.y0) < radius * radius)
				mlx_put_pixel(vars->img, x, y, \
				create_color(255, 255, 255, 255));
			y++;
		}
		x++;
	}
}

/*
-> Trace 512 rayons depuis l’angle du joueur pour détecter les murs, en
recalibrant l’angle à chaque étape pour éviter les débordements.
-> Calcule les intersections horizontales et verticales avec les murs, puis
choisit la plus proche pour déterminer la distance visible.
corrige  l’effet fish-eye.
-> Calcule la hauteur de la ligne à dessiner pour chaque rayon selon la distance
corrigée et dessine le mur correspondant (vertical ou horizontal) à l’écran.*/
void	draw_ray(t_vars *vars)
{
	t_ray_info	ray;
	double		fish_eye_new_angle;
	double		line_height;

	ray.ray = 0;
	ray.ra = vars->player.angle - DEG * 30;
	ft_recalibrate(&(ray.ra));
	while (ray.ray < 512)
	{
		calculate_hor_intersect(vars, &ray);
		calculate_ver_intersect(vars, &ray);
		get_shortest_intersection(vars, &ray, ray.ray);
		fish_eye_new_angle = vars->player.angle - ray.ra;
		ft_recalibrate(&fish_eye_new_angle);
		ray.f_dist = ray.f_dist * cos(fish_eye_new_angle);
		line_height = (64 * 800) / ray.f_dist;
		if (ray.v_dist > ray.h_dist)
			draw_wall(vars, ray, line_height, 0);
		else
			draw_wall(vars, ray, line_height, 1);
		ray.ra = ray.ra + DEG / 8;
		ft_recalibrate(&(ray.ra));
		ray.ray++;
	}
}

/* Code de départ pour afficher un mur sans texture; juste une couleur
void	draw_wal7(t_vars *vars, int r, int lineH, int32_t color)
{
	int		i;
	int		y;
	int		x1;
	int		y1;
	double	ligne_offset;

	i = 0;
	x1 = r * 2 + 513;
	y1 = 220 - lineH / 2;
	ligne_offset = 220 - lineH / 2;
	while (i < 2)
	{
		y = y1;
		while (y <= lineH + (int)ligne_offset)
		{
			mlx_put_pixel(vars->img, x1 - i, y, color);
			y++;
		}
		i++;
	}
}
*/