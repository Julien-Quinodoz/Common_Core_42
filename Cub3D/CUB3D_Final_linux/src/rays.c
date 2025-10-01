/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:51:27 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/17 09:25:15 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*   boucle de détection de mur à partir d’un point initial
	 avance le rayon (avec xo, yo) jusqu’à ce qu’il touche un mur
	 (valeur >= 1 dans la map) ou atteigne 100 depths of field
	 (DOF = limite d'itérations).

	>ray->rx, ray->ry : position actuelle du rayon

	>ray->xo, ray->yo : incréments à chaque étape (delta x/y)
	>wall : structure contenant des pointeurs vers les valeurs où stocker les
	résultats (x, y, distance)*/
void	check_for_wall(t_vars *vars, t_ray_info *ray, t_wall *wall)
{
	while (ray->dof < 100)
	{
		ray->mx = (int)(ray->rx) / 64;
		ray->my = (int)(ray->ry) / 64;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < vars->map.width \
		&& ray->my < vars->map.height && vars->map.map[ray->my][ray->mx] >= 1)
		{
			*wall->x_val = ray->rx;
			*wall->y_val = ray->ry;
			*wall->dist = distance_to_wall(vars->player.x, vars->player.y, \
			*wall->x_val, *wall->y_val);
			break ;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}

/* ->Réinitialise les données de lancement du rayon.
	-> Place le rayon au point de départ (position du joueur).
	-> Met une distance de base grande pour pouvoir réduire plus tard.
	-> Travaille de manière abstraite grâce aux pointeurs passés dans t_wall.
Système, modulaire, et facilite la comparaison entre collisi horiz et verti */
void	ft_initializer(t_vars *vars, t_ray_info *ray, t_wall *wall)
{
	ray->dof = 0;
	*wall->dist = 100000;
	*wall->x_val = vars->player.x;
	*wall->y_val = vars->player.y;
}

/*  intersection avec les murs verticaux
 > rx, ry sont initialisés selon la direction du rayon (angle ra)
 > ntan = -tan(ra) : utilisé pour déterminer la pente inverse
 > Ensuite on appelle check_for_wall pour tester le mur sur cette ligne. */
void	calculate_ver_intersect(t_vars *vars, t_ray_info *ray)
{
	t_wall	wall;

	set_initial_vwall_value(vars, ray, &wall);
	ray->ntan = -tan(ray->ra);
	if (ray->ra > M_PI / 2 && ray->ra < 3 * M_PI / 2)
	{
		ray->rx = (((int)vars->player.x / 64) * 64) - 0.0001;
		ray->ry = (vars->player.x - ray->rx) * ray->ntan + vars->player.y;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->ntan;
	}
	if (ray->ra < M_PI / 2 || ray->ra > 3 * M_PI / 2)
	{
		ray->rx = (((int)vars->player.x / 64) * 64) + 64;
		ray->ry = (vars->player.x - ray->rx) * ray->ntan + vars->player.y;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->ntan;
	}
	if (ray->ra == M_PI / 2 || ray->ra == 3 * M_PI / 2)
	{
		ray->rx = vars->player.x;
		ray->ry = vars->player.y;
		ray->dof = 100;
	}
	check_for_wall(vars, ray, &wall);
}

/*  intersection avec les murs horizontaux
		 >> IDEM que Verticaux <<
			atan = -1 / tan(ra) 			*/
void	calculate_hor_intersect(t_vars *vars, t_ray_info *ray)
{
	t_wall	wall;

	set_initial_hwall_value(vars, ray, &wall);
	ray->atan = -1 / tan(ray->ra);
	if (ray->ra > M_PI)
	{
		ray->ry = (((int)vars->player.y / 64) * 64) - 0.0001;
		ray->rx = (vars->player.y - ray->ry) * ray->atan + vars->player.x;
		ray->yo = -64;
		ray->xo = -ray->yo * ray->atan;
	}
	if (ray->ra < M_PI)
	{
		ray->ry = (((int)vars->player.y / 64) * 64) + 64;
		ray->rx = (vars->player.y - ray->ry) * ray->atan + vars->player.x;
		ray->yo = 64;
		ray->xo = -ray->yo * ray->atan;
	}
	if (ray->ra == 0 || ray->ra == M_PI)
	{
		ray->rx = vars->player.x;
		ray->ry = vars->player.y;
		ray->dof = 100;
	}
	check_for_wall(vars, ray, &wall);
}

/* choisir entre mur horizontal ou vertical le plus court
 > Si v_dist < h_dist, alors collision verticale → rx = v_x, etc.
 > Sinon collision horizontale
 > Un rayon est ensuite tracé entre le joueur et l’impact
 		(si show_map activé) à l’échelle mini-map. */
void	get_shortest_intersection(t_vars *vars, t_ray_info *ray, int i)
{
	t_line	line;

	if (ray->v_dist < ray->h_dist)
	{
		ray->rx = ray->v_x;
		ray->ry = ray->v_y;
		ray->f_dist = ray->v_dist;
	}
	else
	{
		ray->rx = ray->h_x;
		ray->ry = ray->h_y;
		ray->f_dist = ray->h_dist;
	}
	line.x0 = (vars->player.x * 16) / 64;
	line.y0 = (vars->player.y * 16) / 64;
	line.x1 = (ray->rx * 16) / 64;
	line.y1 = (ray->ry * 16) / 64;
	line.map_height = vars->img->height;
	line.map_width = vars->img->width;
	line.color = create_color(50, 255, 190, 240);
	vars->g_ray_ds[i] = ray->f_dist;
	if (vars->keyboard.show_map)
		put_line(&line);
}
