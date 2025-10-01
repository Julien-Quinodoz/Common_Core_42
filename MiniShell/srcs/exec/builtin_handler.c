/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:35:30 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 12:14:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Sets up input/output redirection for commands */
/* Don't close pipin here - it will be handled in process_command */
/* Don't close pipout here - it will be handled in process_command*/
static void	setup_command_io(t_mini *mini)
{
	if (mini->pipin != STDIN_FILENO && mini->pipin != -1)
	{
		dup2(mini->pipin, STDIN_FILENO);
	}
	if (mini->pipout != STDOUT_FILENO && mini->pipout != -1)
	{
		dup2(mini->pipout, STDOUT_FILENO);
	}
}

/* Checks if a command is a built-in shell command */
int	verify_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}

/* Executes a built-in shell command based on the command name */
int	execute_builtin(char **args, t_mini *mini)
{
	int	result;

	if (!args || !args[0] || !mini)
		return (ERROR);
	setup_command_io(mini);
	result = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		result = ft_echo(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		result = ft_cd(args, mini->env);
	else if (ft_strcmp(args[0], "pwd") == 0)
		result = ft_pwd();
	else if (ft_strcmp(args[0], "env") == 0)
		result = ft_env(mini->env);
	else if (ft_strcmp(args[0], "export") == 0)
		result = ft_export(args, mini->env, mini->secret_env);
	else if (ft_strcmp(args[0], "unset") == 0)
		result = ft_unset(args, mini);
	return (result);
}
