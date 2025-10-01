/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:40:54 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/13 15:23:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Cette fonction gère les contrôles clavier du jeu.
Elle vérifie en continu quelles touches sont pressées et exécute les actions
->// On caste le paramètre générique en notre structure principale.
.*/
int	key_press_handler_1(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->game_over)
		return (1);
	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		for_key_right(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		for_key_left(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
		for_key_w(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
		for_key_s(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		for_key_a(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		for_key_d(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_P))
		vars->effects_on = !vars->effects_on;
	return (0);
}

/* gère le mouvement de la souris pour contrôler la rotation du joueur.
	 Elle implémente un système de "mouselook" classique.
	 Permet de regarder autour en bougeant la souris horizontalement
	  Plus la souris bouge vite, plus la rotation est rapide
	1 --> Orienter la caméra/vue du joueur (rotation)
	2 --> Calculer la direction vers laquelle il regarde
	3 --> Préparer les valeurs pour un éventuel déplacement de 5 pixel
==============================================================================
-> ypos est ignoré (pas de mouvement vertical implémenté)
//Calcule la différence entre la position actuelle de la souris et la précédente
// Sauvegarde la position actuelle pour le prochain appel
// Multiplie le déplacement par la sensibilité de la souris
// Ajoute cette rotation à l'angle actuel du joueur
// Maintient l'angle entre 0 et 2π radians (0° à 360°) --> pour éviter les
	débordements et garder des valeurs cohérentes.
// Convertit l'angle en vecteur directionnel unitaire ; dx dy :
	la lettre d veux dire vecteur directionel (position delta)
 // Le facteur 5 définit la vitesse de déplacement du joueur
	*/
void	mouse_handler(double xpos, double ypos, void *param)
{
	t_vars	*vars;
	double	delta_x;
	double	rotation;

	vars = (t_vars *)param;
	(void)ypos;
	delta_x = xpos - vars->player.prev_xpos;
	vars->player.prev_xpos = xpos;
	rotation = delta_x * MOUSE_SENSITIVITY;
	vars->player.angle += rotation;
	if (vars->player.angle > 2 * M_PI)
		vars->player.angle -= 2 * M_PI;
	if (vars->player.angle < 0)
		vars->player.angle += 2 * M_PI;
	vars->player.dx = 5 * cos(vars->player.angle);
	vars->player.dy = 5 * sin(vars->player.angle);
}

/*Contrôler la fréquence de redessin de l'écran; dessine que une framme sur 5
	Éviter de surcharger le processeur avec des redraws inutiles
	Maintenir une animation fluide mais optimisée
	 Après 10000 frames, on remet le compteur à zéro. */
void	loop_func(void *data)
{
	static int	frame = 0;
	t_vars		*vars;

	vars = (t_vars *)data;
	if (frame % 5 == 0)
		redraw(vars);
	if (frame > 10000)
		frame = 0;
	frame++;
}
