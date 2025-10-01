/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:32:26 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 17:31:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
-> Parcourt deux colonnes verticales pour dessiner la texture du mur sur l’image.
-> Calcule à chaque pixel la couleur correspondante dans la texture
		à partir de coordonnées flottantes.
-> Affiche le pixel sur l’image ou une couleur transparente */
void	draw_it(t_vars *vars, t_draw_value *info, int lineH)
{
	int	i;
	int	y;

	i = -1;
	while (++i < 2)
	{
		info->in = 0;
		info->rl = info->y2;
		y = info->y1 - 3;
		while (++y <= lineH + (int)info->ligne_offset && y < 1023)
		{
			info->in = 512 * 4 * (int)floor(info->rl);
			if (info->theline + info->in < (int)info->imgtxet->height
				* (int)info->imgtxet->width * 4)
				info->color = collect_color(info->imgtxet->pixels,
						(info->theline) + info->in);
			else
				info->color = create_color(0, 0, 0, 0);
			mlx_put_pixel(vars->img, info->x1 - i, y, info->color);
			info->rl += info->g;
		}
	}
}

/*Cette fonction choisit la texture EST ou OUEST à afficher selon la position
verticale du joueur par rapport au mur touché. Elle ajuste l’orientation du
découpage de la texture en fonction de l’angle du j.*/
void	decide_horizontal_textures(t_vars *vars, t_draw_value *info, int rx)
{
	if (vars->player.x > rx)
		info->imgtxet = vars->ea_wall_texture;
	else
		info->imgtxet = vars->we_wall_texture;
	if (vars->player.angle > M_PI / 2 && vars->player.angle < 3 * M_PI / 2)
		info->porcentsage = 1 - info->porcentsage;
}

/*Cette fonction choisit la texture nord ou sud à afficher selon la position
verticale du joueur par rapport au mur touché. Elle ajuste l’orientation du
découpage de la texture en fonction de l’angle du j.*/
void	decide_vertical_textures(t_vars *vars, t_draw_value *info, int ry)
{
	if (vars->player.y > ry)
		info->imgtxet = vars->no_wall_texture;
	else
		info->imgtxet = vars->so_wall_texture;
	if (vars->player.angle < M_PI)
		info->porcentsage = 1 - info->porcentsage;
}

/* calcule et ajuste des paramètres pour dessiner une ligne verticale
représentant un mur avec du raycasting. Elle s’assure que la hauteur ne
dépasse pas une limite et centre la ligne sur l’écran.*/
int	draw_wall_data(t_draw_value *info, int lineH)
{
	info->k = lineH;
	if (lineH > 1020)
		lineH = 1020;
	info->ligne_offset = 512 - lineH / 2;
	info->y1 = 512 - lineH / 2;
	info->y2 = (float)(info->k / 2 - 512) / info->k * 512;
	if (info->y2 < 0)
		info->y2 = 0;
	return (lineH);
}
