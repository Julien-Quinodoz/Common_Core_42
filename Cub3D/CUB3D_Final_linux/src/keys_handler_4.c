/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:07 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 19:19:18 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
Prépare les données nécessaires au déplacement en calculant les coordonnées des
	 cases de la map qu’il va potentiellement occuper.
Avant (W) :
-> Calcule une vitesse normale de 1.5, doublée à 3 si Shift est enfoncé.
-> Détermine la case visée à 3 unités devant le joueur (info->x / info->y).
-> Calcule également une case de  1 unité devant pour éviter les collisions.

Arrière (S) :
 -> Similaire, mais avec des déplacements vers l’arrière (2 et 1 unités)
 	pour permettre un recul fluide.

Dans les deux cas :
info->factx et info->facty enregistrent la case actuelle du joueur
(convertie les coordonnées pixels), utile pour les comparaisons avec la map)
*/
static void	init_for_keys_w_s(t_vars *vars, t_key_value *info, int for_w)
{
	if (for_w)
	{
		info->speed = 1.5;
		if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT_SHIFT))
			info->speed = 3;
		info->x = (int)floor((vars->player.x + (vars->player.dx * 3)) / 64);
		info->y = (int)floor((vars->player.y + (vars->player.dy * 3)) / 64);
		info->xcheck = (int)floor((vars->player.x + (vars->player.dx)) / 64);
		info->ycheck = (int)floor((vars->player.y + (vars->player.dy)) / 64);
		info->factx = (int)floor((vars->player.x) / 64);
		info->facty = (int)floor((vars->player.y) / 64);
		return ;
	}
	info->x = (int)floor((vars->player.x - (vars->player.dx * 2)) / 64);
	info->y = (int)floor((vars->player.y - (vars->player.dy * 2)) / 64);
	info->xcheck = (int)floor((vars->player.x - (vars->player.dx)) / 64);
	info->ycheck = (int)floor((vars->player.y - (vars->player.dy)) / 64);
	info->factx = (int)floor((vars->player.x) / 64);
	info->facty = (int)floor((vars->player.y) / 64);
}

/*
 Gère l'avancement du joueur vers l'avant (touche W) :
 - Vérifie si les cases devant le joueur sont libres.
 - Empêche de traverser les coins muraux en diagonale.
 - Permet un glissement contre les murs si l'avancée frontale est bloquée.
*/
void	for_key_w(t_vars *vars)
{
	t_key_value	info;

	init_for_keys_w_s(vars, &info, 1);
	if (vars->map.map[info.y][info.x] <= 0
		&& vars->map.map[info.ycheck][info.xcheck] <= 0)
	{
		if (!(info.x != info.factx && info.y != info.facty \
				&& vars->map.map[info.y][info.factx] > 0 \
				&& vars->map.map[info.facty][info.x] > 0))
		{
			vars->player.x += vars->player.dx * info.speed;
			vars->player.y += vars->player.dy * info.speed;
		}
	}
	else
	{
		if (vars->map.map[info.facty][info.x] <= 0
			&& vars->map.map[info.facty][info.xcheck] <= 0)
			vars->player.x += vars->player.dx;
		else if (vars->map.map[info.y][info.factx] <= 0
			&& vars->map.map[info.ycheck][info.factx] <= 0)
			vars->player.y += vars->player.dy;
	}
}

/*// Idem que key W mais inversée */
void	for_key_s(t_vars *vars)
{
	t_key_value	info;

	init_for_keys_w_s(vars, &info, 0);
	if (vars->map.map[info.y][info.x] <= 0
		&& vars->map.map[info.ycheck][info.xcheck] <= 0)
	{
		if (!(info.x != info.factx && info.y != info.facty
				&& vars->map.map[info.y][info.factx] > 0
			&& vars->map.map[info.facty][info.x] > 0))
		{
			vars->player.x -= vars->player.dx;
			vars->player.y -= vars->player.dy;
		}
	}
	else
	{
		if (vars->map.map[info.facty][info.x] <= 0
			&& vars->map.map[info.facty][info.xcheck] <= 0)
			vars->player.x -= vars->player.dx;
		else if (vars->map.map[info.y][info.factx] <= 0
				&& vars->map.map[info.ycheck][info.factx] <= 0)
			vars->player.y -= vars->player.dy;
	}
}

/*

static void	init_for_keys_w_s(t_vars *vars, t_key_value *info, int for_w)
{
	if (for_w)
	{
		info->speed = 1.5;
		if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT_SHIFT))
			info->speed = 3;
		info->x = (int)floor((vars->player.x + (vars->player.dx * 3)) / 64);
		// inscrit dans info->x le numéro entier de la case (sur l’axe X)
		que le joueur atteindrait en avançant de 3 unités dans sa direction
		actuelle.
		info->y = (int)floor((vars->player.y + (vars->player.dy * 3)) / 64);
		info->xcheck = (int)floor((vars->player.x + (vars->player.dx)) / 64);
		 // même que info->x mais  que de 1 case , 1 pas .
		info->ycheck = (int)floor((vars->player.y + (vars->player.dy)) / 64);
		info->factx = (int)floor((vars->player.x) / 64); // position du joueur;
		 /64 on convertit les pixels en numéro de case; On arrondit vers le
		 bas pour tomber dans la bonne case
		info->facty = (int)floor((vars->player.y) / 64);
		return ;
	}
	info->x = (int)floor((vars->player.x - (vars->player.dx * 2)) / 64);
	 // Idem avec des - pour reculer avec S
	info->y = (int)floor((vars->player.y - (vars->player.dy * 2)) / 64);
	 //  quand tu recules (S), tu ne parcours généralement que peu de distance,
	  souvent en cas de manœuvre courte (recul pour esquiver, sortir d’un coin)
	info->xcheck = (int)floor((vars->player.x - (vars->player.dx)) / 64);
	// -2 permet de reculer sans trop restreindre le joueur
	info->ycheck = (int)floor((vars->player.y - (vars->player.dy)) / 64);
	info->factx = (int)floor((vars->player.x) / 64);
	info->facty = (int)floor((vars->player.y) / 64);
}

void	for_key_w(t_vars *vars)
{
	t_key_value	info;	//contient les coordonnées utiles pour teste
	les collisions.

	init_for_keys_w_s(vars, &info, 1);
	// Initialise la structure info avec des données calculées avec vars
	(1 = W ; 0 = S)
	if (vars->map.map[info.y][info.x] <= 0
	// Vérifie si les deux cases devant (map[y][x] et map[ycheck][xcheck])
	sont libres (pas de mur).
		&& vars->map.map[info.ycheck][info.xcheck] <= 0)
	{
		if (!(info.x != info.factx && info.y != info.facty
		//Empêche le joueur de glisser entre deux murs en diagonale
		(ex : coin entre mur de gauche et mur du haut).
				&& vars->map.map[info.y][info.factx] > 0
				&& vars->map.map[info.facty][info.x] > 0))
	// vérifie que si on est en diagonale (x ≠ factx && y ≠ facty);
	 alors il faut que l’un des coins ne soit pas un mur pour avancer.
		{
			vars->player.x += vars->player.dx * info.speed;
			// Avance --> Si les deux tests précédents passent,
			le joueur peut avancer normalement dans la direction de son regard.
			vars->player.y += vars->player.dy * info.speed;
		}
	}
	else	// . Sinon : tenter un glissement contre le mur
	{
		if (vars->map.map[info.facty][info.x] <= 0
		// Glissement sur X :
			&& vars->map.map[info.facty][info.xcheck] <= 0)
			vars->player.x += vars->player.dx;
		else if (vars->map.map[info.y][info.factx] <= 0
		//  Glissement sur Y :
				&& vars->map.map[info.ycheck][info.factx] <= 0)
			vars->player.y += vars->player.dy;
	}
} */