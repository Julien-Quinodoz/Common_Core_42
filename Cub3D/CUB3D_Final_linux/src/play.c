/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:27:49 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/18 10:16:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_time_remaining(t_vars *vars)
{
	time_t	current_time;
	int		remaining;
	int		elapsed;

	current_time = time(NULL);
	elapsed = (int)(current_time - vars->start_time);
	remaining = 121 - elapsed;
	if (remaining < 0)
		remaining = 0;
	return (remaining);
}

void	update_taches(t_vars *vars)
{
	int		remaining;
	int		taches_should_be;
	t_tache	*t;

	if (!vars->effects_on)
		return ;
	remaining = get_time_remaining(vars);
	taches_should_be = (100 - remaining) / 2;
	while (vars->tache_count < taches_should_be
		&& vars->tache_count < MAX_TACHES)
	{
		t = &vars->taches[vars->tache_count];
		t->x = rand() % (vars->window_info.width - 100);
		t->y = rand() % (vars->window_info.height - 100);
		t->w = 100 + rand() % 50;
		t->h = 100 + rand() % 50;
		t->color = 0x22AA66FF;
		vars->tache_count++;
	}
}

static void	draw_pixel_if_in_circle(t_circle_params *p, int x, int y)
{
	int	radius_variation;
	int	dist_sq;
	int	draw_x;
	int	draw_y;
	int	random_percent;

	radius_variation = p->base_radius + (rand() % 5 - 2);
	dist_sq = x * x + y * y;
	if (dist_sq <= radius_variation * radius_variation)
	{
		draw_x = p->cx + x;
		draw_y = p->cy + y;
		if (draw_x >= 0 && draw_x < (int)p->img->width
			&& draw_y >= 0 && draw_y < (int)p->img->height)
		{
			random_percent = rand() % 100;
			if (random_percent > 40)
				mlx_put_pixel(p->img, draw_x, draw_y, p->color);
		}
	}
}

void	draw_baveuse_circle(t_circle_params *p)
{
	int	x;
	int	y;
	int	limit;

	limit = p->base_radius + 2;
	y = -limit;
	while (y <= limit)
	{
		x = -limit;
		while (x <= limit)
		{
			draw_pixel_if_in_circle(p, x, y);
			x++;
		}
		y++;
	}
}
/*
void	draw_baveuse_circle(mlx_image_t *img, int cx, int cy, \
	int base_radius, uint32_t color)
{
	int x;
	int y;
	int radius_variation;
	int dist_sq;
	int draw_x;
	int draw_y;

	y = -base_radius - 2;
	while (y <= base_radius + 2)
	{
		x = -base_radius - 2;
		while (x <= base_radius + 2)
		{
			radius_variation = base_radius + (rand() % 5 - 2);
			dist_sq = x * x + y * y;
			if (dist_sq <= radius_variation * radius_variation)
			{
				draw_x = cx + x;
				draw_y = cy + y;
				if (draw_x >= 0 && draw_x < (int)img->width && draw_y >= 0 \
					&& draw_y < (int)img->height)
				{
					if ((rand() % 100) > 40)
						mlx_put_pixel(img, draw_x, draw_y, color);
				}
			}
			x++;
		}
		y++;
	}
}
*/

void	play_action(t_vars *vars)
{
	int				i;
	t_circle_params	params;
	t_tache			*t;

	i = 0;
	update_taches(vars);
	if (vars->effects_on)
		draw_timer(vars);
	while (i < vars->tache_count)
	{
		t = &vars->taches[i];
		params.img = vars->img;
		params.cx = t->x;
		params.cy = t->y;
		params.base_radius = t->w / 2;
		params.color = t->color;
		draw_baveuse_circle(&params);
		i++;
	}
	if (vars->game_over)
	{
		mlx_put_string(vars->mlx, "=== GAME OVER ===", 420, 420);
		return ;
	}
}
