/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:43:26 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/18 10:17:25 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Créer une valeur de couleur unique (sous forme d'un entier 32 bits) à partir
 des composantes rouge (r), verte (g), bleue (b) et alpha (a) pour une
 utilisation dans un rendu graphique, MLX42.*/
int32_t	create_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/* Calculer la distance entre deux points dans un espace 2D :
 la position du joueur (px, py) et un point sur un mur (wx, wy).
 Cette distance détermine la hauteur des murs à l'écran et corrige
 l'effet de fisheye.
   ↑
 5 | . . . P . . . . .
 4 | . . . . . . . . .
 3 | . . . . . . . . .
 2 | . . . . . . W . .
 1 | . . . . . . . . .
 0 | . . . . . . . . .
    0 1 2 3 4 5 6 7 → x
======================
   y
   ↑
 5 | . . . P ─ ─ ─ ┐ . .
 4 | . . . │       │ . .
 3 | . . . │       │ . .
 2 | . . . └───────W . .
 1 | . . . . . . . . . .
 0 | . . . . . . . . . .
    0 1 2 3 4 5 6 7 → x

Puis on applique le théorème de Pythagore (racine carrée (sqrt))
pour obtenir l’hypoténuse du triangle
rectangle ; donc la distance !
======================= */
float	distance_to_wall(float px, float py, float wx, float wy)
{
	return (sqrt((wy - py) * (wy - py) + (wx - px) * (wx - px)));
}

void	draw_timer(t_vars *vars)

{
	char	str[64];
	int		remaining;
	int		minutes;
	int		seconds;

	remaining = get_time_remaining(vars);
	minutes = remaining / 60;
	seconds = remaining % 60;
	if (remaining <= 0)
	{
		vars->game_over = 1;
		remaining = 0;
	}
	snprintf(str, sizeof(str), "⏳ Temps restant : %02d:%02d", minutes, seconds);
	if (vars->timer_img)
		mlx_delete_image(vars->mlx, vars->timer_img);
	vars->timer_img = mlx_put_string(vars->mlx, str, 700, 130);
}

void	init_play_features(t_vars *vars)
{
	vars->tache_count = 0;
	vars->effects_on = 0;
	vars->start_time = time(NULL);
	vars->game_over = 0;
}
