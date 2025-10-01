/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:32:18 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/12 17:49:53 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Construit dynamiquement le chemin d’une image PNG à partir d’un numéro de
frame pour charger la texture correspondante via mlx_load_png. Elle sert à animer
un sprite en sélectionnant automatiquement la bonne image selon l’état de
l’animation.(frame / 2)= divise par 2 pour ralentir la boucle des frame)*/
void	get_sprite_texture(int frame, char *sprite_path,
		mlx_texture_t **imgtxet)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(frame / 2);
	str = ft_strjoin(sprite_path, tmp);
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ".png");
	(*imgtxet) = mlx_load_png(str);
	free(tmp);
	free(str);
}

/* dessine verticalement un sprite (image 2D) sur l'écran, colonne par colonne
(while) dans une autre boucle while;  en fonction  de :
->l’échelle à appliquer (hauteur / largeur du sprite),
->des pixels transparents à ignorer,
->de l’emplacement du sprite à l’écran (x1, y1),
->de la texture (stockée dans imgtxet).*/
void	draw_the_sprite_while_in_while(t_vars *vars, t_sp *sp,
		t_sprite_value *info)
{
	int	i;
	int	y;

	i = 0;
	while (i < 2)
	{
		info->tot_h = 0;
		info->suu = (int)info->tot_v * 4;
		info->lol = (int)(info->tot_h * 160 * 4) + info->suu;
		y = info->y1;
		while (y <= sp->line_height + (int)info->ligne_offset && y < 1024)
		{
			if (info->lol < (int)info->imgtxet->height
				* (int)info->imgtxet->width * 4)
				info->color = collect_color(info->imgtxet->pixels,
						info->lol);
			if (info->color != info->trans)
				mlx_put_pixel(vars->img, info->x1 - i, y, info->color);
			info->tot_h += info->por_h;
			info->lol = (int)info->tot_h * 160 * 4 + info->suu;
			y++;
		}
		info->tot_v += info->por_v;
		i++;
	}
}

/* Cette fonction parcourt les colonnes visibles d’un sprite et dessine chaque
colonne seulement si le sprite est plus proche que le mur à cet endroit, assurant
ainsi la bonne gestion de la profondeur. Elle met à jour le buffer de profondeur
et appelle une fonction pour dessiner verticalement chaque colonne du sprite.*/
void	draw_the_sprite_while(t_vars *vars, t_sp *sp, t_sprite_value *info)
{
	while (info->time < (int)sp->porce_angle + (sp->line_height / 10)
		&& info->time < 512)
	{
		if (sp->v_dist < vars->g_ray_ds[info->time])
		{
			vars->g_ray_ds[info->time] = sp->v_dist;
			info->x1 = info->time * 2 + 2;
			draw_the_sprite_while_in_while(vars, sp, info);
		}
		else
			info->tot_v += 2 * info->por_v;
		info->time++;
	}
}

/* Cette fonction prépare les paramètres de rendu d’un sprite (position, taille,
découpage vertic. /horizont. dans la texture) en fonction de la distance et de la
taille du sprite à l’écran, charge la texture du sprite pour la frame demandée
puis appelle la fonction qui dessine le sprite colonne par colonne avec gestion
 de la profondeur. Et, elle libère la texture chargée pour éviter les fuites */

void	draw_the_sprite(t_vars *vars, t_sp *sp, int frame, char *sprite_path)
{
	t_sprite_value	info;

	info.trans = create_color(0, 0, 0, 0);
	info.x1 = (int)sp->porce_angle * 2 + 2;
	if (sp->line_height > 1020)
		sp->line_height = 1020;
	info.ligne_offset = 512 - sp->line_height / 2.9;
	info.y1 = 512 - sp->line_height / 2.9;
	info.por_h = 608 / sp->line_height;
	info.tot_h = 0;
	info.por_v = 160 / (4 * sp->line_height / 10);
	info.tot_v = 0;
	info.lol = 0;
	info.suu = 0;
	info.time = sp->porce_angle - (sp->line_height / 10);
	if (info.time < 0)
	{
		info.tot_v += abs(info.time * 2) * info.por_v;
		info.time = 0;
	}
	get_sprite_texture(frame, sprite_path, &info.imgtxet);
	draw_the_sprite_while(vars, sp, &info);
	mlx_delete_texture(info.imgtxet);
}

/* Calcule la position horizontale, la distance et la taille à l’écran d’un
 sprite avant de l’afficher. Elle sert à rendre un sprite animé avec la
 bonne texture avec la distance et de l’angle par rapport au joueur.*/
void	draw_one_sprite_norm(t_vars *vars, t_sp *sp, int frame, int i)
{
	sp->porce_angle = (sp->porce_angle + 30) / 60 * 512;
	sp->v_dist = distance_to_wall(vars->player.x, \
	vars->player.y, sp->sprite_ax, sp->sprite_ay);
	sp->line_height = (64 * 600) / sp->v_dist;
	draw_the_sprite(vars, sp, frame, vars->sprites[i].path);
}
