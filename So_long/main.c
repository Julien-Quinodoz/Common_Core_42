/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:50:02 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/26 08:56:26 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	static t_game	game;
	static t_map	map;

	game.map = &map;
	if (ac == 2)
	{
		ber_file_check(av[1], &game);
		(game.map)->path = av[1];
		create_map(&game);
		map_format_check(&game);
		if ((game.map)->height > 20 || (game.map)->width > 40)
			print_error_message("Error: window size extends from screen\n",
				&game);
		create_game_interface(&game);
		free_map((game.map)->vector);
	}
	else
		ft_printf("Error: 2 arguments must be entered!\n");
	return (0);
}
