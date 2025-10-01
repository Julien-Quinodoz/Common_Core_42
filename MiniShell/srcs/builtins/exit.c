/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:38:25 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 19:58:24 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_numeric_error(t_mini *mini, char *arg)
{
	mini->ret = 255;
	ft_putstr_fd("exit: 💀 \n", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required for error code", 2);
}

static void	exit_too_many_args(t_mini *mini)
{
	mini->ret = 1;
	ft_putstr_fd("exit: 💀 \n", 2);
	ft_putendl_fd("too many arguments", 2);
	exit(mini->ret);
}

/*
 * Gère la commande 'exit' avec la gestion des arguments et du code de retour
 	1. Si aucun argument n'est passé, (!cmd[1]) :
		quitte avec le message "bye 🍺" et un code de retour 0.
 	2. Si plus d'un argument est passé, affiche une erreur "too many arguments"
		et quitte avec le code 1.
	3. Si l'argument n'est pas un nombre -- quitte avec le message
		" 💀 numérique argu. required" ret 255.
	4. si 1 arg  valide :atoi le nombre arg dans mini->ret et quite proprement.
 */
void	mini_exit(t_mini *mini, char **cmd)
{
	mini->exit = 1;
	if (!cmd[1])
	{
		ft_putendl_fd("BYE 🍺", 2);
		exit(0);
	}
	if (cmd[2])
	{
		exit_too_many_args(mini);
	}
	if (!ft_strisnum(cmd[1]))
	{
		exit_numeric_error(mini, cmd[1]);
		exit(mini->ret);
	}
	mini->ret = ft_atoi(cmd[1]);
	ft_putstr_fd("exit ", 2);
	ft_putendl_fd("💔", 2);
	exit(mini->ret);
}
