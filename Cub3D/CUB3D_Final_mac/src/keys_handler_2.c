/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:03:41 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 19:49:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* gére les déplacements après que les calculs de position ont été effectués.
	vérifie si le déplacement latéral est valide en évitant les collisions avec
	les murs, puis met à jour la position si le mouvement est autorisé.
-> si tout ok ; déplassement ; si non essaie un déplacement partiel
	*/
static void	return_handler(t_vars *vars, t_key_value *info)
{
	if (vars->map.map[info->y][info->x] <= 0
		&& vars->map.map[info->ycheck][info->xcheck] <= 0)
	{
		if (!(info->x != info->factx && info->y != info->facty
				&& vars->map.map[info->y][info->factx] > 0
			&& vars->map.map[info->facty][info->x] > 0))
		{
			vars->player.x += info->dxright;
			vars->player.y += info->dyright;
		}
	}
	else
	{
		if (vars->map.map[info->facty][info->x] <= 0
			&& vars->map.map[info->facty][info->xcheck] <= 0)
			vars->player.x += info->dxright;
		else if (vars->map.map[info->y][info->factx] <= 0
				&& vars->map.map[info->ycheck][info->factx] <= 0)
			vars->player.y += info->dyright;
	}
}

/* initialise INFO pour gerer le déplacement du joueur avec touche A gauche
	calcule les nouvelles coordonnées du joueur et effectue des vérifications
	pour s'assurer que le déplacement est ok ->return_handler pour deplacement
	=========================================>
void	for_key_a(t_vars *vars)
{
	info.dxright = 5 * cos(vars->player.angle - M_PI / 2);
	>> calculent le vecteur de déplacement pour un mouvement latéral gauche :
			- M_PI / 2 -> (90 degrés) est soustrait à l'angle pour obtenir la
			direction perpendiculaire à gauche
	info.dyright = 5 * sin(vars->player.angle - M_PI / 2);
	>> dxright et dyright donnent les déplacements en x et y pour un pas dans
		la direction à gauche. 5 pixel pour la grandeur du pas ou vitesse
	info.x = (int)floor((vars->player.x + (info.dxright * 3)) / 64);
	>> calculent la position dans la grille où le joueur se retrouverait après
		un déplacement de 3 pas
	info.y = (int)floor((vars->player.y + (info.dyright * 3)) / 64);
	>> La division par 64 convertit en pixels les coordonnées de la grille
	info.xcheck = (int)floor((vars->player.x + (info.dxright)) / 64);
	>> calculent la position dans la grille après un seul pas (sans le * 3).
	info.ycheck = (int)floor((vars->player.y + (info.dyright)) / 64);
	info.factx = (int)floor((vars->player.x) / 64);
	>> calculent la case (INT) actuelle du joueur dans la grille, en
		convertissant ses coordonnées en pixels
	info.facty = (int)floor((vars->player.y) / 64);
	>> Comparer la position actuelle avec les positions futures
		(x, y, xcheck, ycheck) pour vérifier si le déplacement est valide.
	return_handler(vars, &info);
} */
void	for_key_a(t_vars *vars)
{
	t_key_value	info;

	info.dxright = 5 * cos(vars->player.angle - M_PI / 2);
	info.dyright = 5 * sin(vars->player.angle - M_PI / 2);
	info.x = (int)floor((vars->player.x + (info.dxright * 3)) / 64);
	info.y = (int)floor((vars->player.y + (info.dyright * 3)) / 64);
	info.xcheck = (int)floor((vars->player.x + (info.dxright)) / 64);
	info.ycheck = (int)floor((vars->player.y + (info.dyright)) / 64);
	info.factx = (int)floor((vars->player.x) / 64);
	info.facty = (int)floor((vars->player.y) / 64);
	return_handler(vars, &info);
}

/*IDEM que A , mais du côté droit */
void	for_key_d(t_vars *vars)
{
	t_key_value	info;

	info.dxright = 5 * cos(vars->player.angle + M_PI / 2);
	info.dyright = 5 * sin(vars->player.angle + M_PI / 2);
	info.x = (int)floor((vars->player.x + (info.dxright * 3)) / 64);
	info.y = (int)floor((vars->player.y + (info.dyright * 3)) / 64);
	info.xcheck = (int)floor((vars->player.x + (info.dxright)) / 64);
	info.ycheck = (int)floor((vars->player.y + (info.dyright)) / 64);
	info.factx = (int)floor((vars->player.x) / 64);
	info.facty = (int)floor((vars->player.y) / 64);
	return_handler(vars, &info);
}

/* gère la rotation du joueur vers la droite, avec mise à jour de dx et dy*/
void	for_key_right(t_vars *vars)
{
	vars->player.angle += 0.1;
	if (vars->player.angle > 2 * M_PI)
		vars->player.angle -= 2 * M_PI;
	vars->player.dx = 5 * cos(vars->player.angle);
	vars->player.dy = 5 * sin(vars->player.angle);
}

/* gère la rotation du joueur vers la gauche , avec mise à jour de dx et dy*/
void	for_key_left(t_vars *vars)
{
	vars->player.angle -= 0.1;
	if (vars->player.angle < 0)
		vars->player.angle += 2 * M_PI;
	vars->player.dx = 5 * cos(vars->player.angle);
	vars->player.dy = 5 * sin(vars->player.angle);
}
