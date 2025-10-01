/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:44 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/09 14:32:01 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_args_len(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
/*
	"i = 1 " On commence au deuxième argument (le premier est  echo)
		Flag pour détecter l'option -n
	1. On vérifie les arguments qui commencent par -n pour ne pas ajouter \n
	2. On affiche tous les arguments restants après les éventuels -n
	3. Si le flag n n'est pas activé, on ajoute un saut de ligne à la fin */

int	ft_echo(char **args)
{
	int		i;
	int		flag_n;

	i = 1;
	flag_n = 0;
	if (ft_args_len(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			flag_n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (flag_n == 0)
		write(1, "\n", 1);
	return (0);
}
