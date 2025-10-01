/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:44:17 by jquinodo          #+#    #+#             */
/*   Updated: 2025/06/13 16:57:30 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_vars				*g_vars;

/*	une façon simple de créer de la variété visuelle sans  randomisation.
	Les sprites alternent entre deux types selon leur position Y, */
static void	assign_sprite_texture_by_row(int sprite, int i)
{
	if (i % 2 == 0)
		g_vars->sprites[sprite].path = \
		ft_strdup("./textures/sprites/");
	else
		g_vars->sprites[sprite].path = \
		ft_strdup("./textures/sprites/g");
}

/* parcourt la carte 2D et trouve les case marquée -2 assignées au parsing,
	convertit la position avec : 64(pixels) * position + 32 pour les centrer.
	Assigne une texture à chaque sprite selon sa ligne (paire/impaire),
	nettoie la carte en remplaçant les -2 par 0.*/
static void	init_pos_sprites(t_map_info *data)
{
	int	i;
	int	j;
	int	sprite;

	i = -1;
	sprite = 0;
	g_vars->numerof_sprite = data->number_of_sprites;
	g_vars->sprites = malloc(sizeof(t_sprite) * g_vars->numerof_sprite);
	while (++i < data->y_map_size)
	{
		j = -1;
		while (++j < data->x_map_size)
		{
			if (data->map[i][j] == -2 && sprite < 15)
			{
				g_vars->sprites[sprite].x = 64 * j + 32;
				g_vars->sprites[sprite].y = 64 * i + 32;
				assign_sprite_texture_by_row(sprite, i);
				data->map[i][j] = 0;
				sprite++;
			}
		}
	}
}

/* initialise : data - vars sprites & lance le rendu et boulce de jeu
srand(time(NULL)); ->  pour générer des taches aléatoires différentes
						à chaque lancement*/
int	main(int argc, char **argv)
{
	t_map_info	data;

	if (argc != 2)
	{
		printf("❌ map required ❌\n");
		exit (1);
	}
	lets_go(argv, &data);
	if (!init_vars(&data))
		return (0);
	init_pos_sprites(&data);
	srand(time(NULL));
	render_window(g_vars);
	return (0);
}
