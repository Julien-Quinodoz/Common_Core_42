/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:39:15 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/16 14:20:05 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *path)
{
	DIR	*folder;
	int	fd;
	int	ret;

	fd = open(path, O_WRONLY);
	folder = opendir(path);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	if (ft_strchr(path, '/') == NULL)
		ft_putendl_fd(": command not found", STDERR);
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": No such file or directory", STDERR);
	else if (fd == -1 && folder != NULL)
		ft_putendl_fd(": is a directory", STDERR);
	else if (fd != -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", STDERR);
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = UNKNOWN_COMMAND;
	else
		ret = IS_DIRECTORY;
	if (folder)
		closedir(folder);
	ft_close(fd);
	return (ret);
}

static void	handle_valid_cmd(char **cmd, int i, t_mini *mini)
{
	char	*tmp;

	if (ft_strchr(cmd[i], '$'))
	{
		tmp = expansions(cmd[i], mini->env, mini->ret);
		if (tmp)
		{
			free(cmd[i]);
			cmd[i] = tmp;
		}
	}
}

static int	should_skip_cmd(char **cmd, int i)
{
	if (!cmd[i] || !*cmd[i])
		return (1);
	if (cmd[i][0] == '$' && cmd[i][1] == '\0')
		return (1);
	return (0);
}

void	expand_args(char **cmd, t_mini *mini)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	while (cmd[i])
	{
		if (should_skip_cmd(cmd, i))
		{
			i++;
			continue ;
		}
		handle_valid_cmd(cmd, i, mini);
		i++;
	}
}
