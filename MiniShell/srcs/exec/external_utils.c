/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:22:41 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/15 19:44:47 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *Main function to execute an external command.
 *Finds the command using $PATH, then calls exec_cmd to run it.
 *Handles cases where PATH is not set or command is given with a path.
 *Example: execute_external({"ls", "-l", NULL}, env, mini)
 */
int	execute_external(char **args, t_env *env, t_mini *mini)
{
	char	**path_dirs;
	char	*path_value;
	char	*exec_path;
	int		result;

	if (!args || !args[0] || args[0][0] == '\0' || args[0][0] == '$')
	{
		mini->ret = 127;
		return (UNKNOWN_COMMAND);
	}
	path_value = get_env_value("PATH", env);
	if (!path_value || !*path_value)
		return (exec_cmd(args[0], args, env, mini));
	path_dirs = ft_split(path_value, ':');
	free(path_value);
	if (!path_dirs)
		return (ERROR);
	exec_path = find_command_path(args[0], path_dirs);
	if (exec_path)
		result = exec_cmd(exec_path, args, env, mini);
	else
		result = exec_cmd(args[0], args, env, mini);
	free_tab(path_dirs);
	free(exec_path);
	return (result);
}
