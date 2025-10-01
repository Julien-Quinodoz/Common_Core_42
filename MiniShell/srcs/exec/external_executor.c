/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:25:10 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 12:23:00 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *Checks if command 'cmd' exists within the opened directory 'dir'.
 *If found, constructs and returns the full path (e.g., "/bin/ls").
 *Example: check_in_dir(dir, "ls", "/bin") -> returns "/bin/ls" if found.
 */
static char	*check_in_dir(DIR *dir, char *cmd, char *dir_path)
{
	struct dirent	*entry;
	char			*path;
	char			*temp;

	entry = readdir(dir);
	while (entry != NULL)
	{
		if (ft_strcmp(entry->d_name, cmd) == 0)
		{
			temp = ft_strjoin(dir_path, "/");
			path = ft_strjoin(temp, cmd);
			free(temp);
			closedir(dir);
			return (path);
		}
		entry = readdir(dir);
	}
	return (NULL);
}

/*
 *Searches through the directories listed in 'dirs' (from $PATH)
 *for the command 'cmd'. Uses check_in_dir for each directory.
 *Returns the full path if found, NULL otherwise.
 *Example: find_command_path("ls", {"/usr/bin", "/bin"}) -> returns "/bin/ls".
 */
char	*find_command_path(char *cmd, char **dirs)
{
	DIR		*dir;
	char	*path;
	int		i;

	i = 0;
	while (dirs && dirs[i])
	{
		dir = opendir(dirs[i]);
		if (!dir)
		{
			i++;
			continue ;
		}
		path = check_in_dir(dir, cmd, dirs[i]);
		if (path)
			return (path);
		closedir(dir);
		i++;
	}
	return (NULL);
}

/* Sets up I/O for child: stdin from fdin/pipin, stdout from fdout/pipout. */
static void	setup_process_io(t_mini *mini)
{
	if (mini->fdin != -1)
	{
		dup2(mini->fdin, STDIN_FILENO);
		close(mini->fdin);
	}
	else if (mini->pipin != -1)
	{
		dup2(mini->pipin, STDIN_FILENO);
	}
	if (mini->fdout != -1)
	{
		dup2(mini->fdout, STDOUT_FILENO);
		close(mini->fdout);
	}
	else if (mini->pipout != -1)
	{
		dup2(mini->pipout, STDOUT_FILENO);
	}
}

/*
 * Handles the result from the child process
 */
static int	handle_child_result(int status, t_mini *mini)
{
	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_sig.exit_status);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status == UNKNOWN_COMMAND)
			mini->ret = 127;
		return (status);
	}
	return (ERROR);
}

/*
 * Executes the command specified by 'path' using fork and execve.
 * Example: exec_cmd("/bin/ls", {"ls", "-l", NULL}, env, mini)
 */
int	exec_cmd(char *path, char **args, t_env *env, t_mini *mini)
{
	int		status;
	char	**env_array;
	char	*env_str;

	g_sig.pid = fork();
	if (g_sig.pid == 0)
	{
		env_str = env_to_str(env);
		env_array = ft_split(env_str, '\n');
		free(env_str);
		setup_process_io(mini);
		if (execve(path, args, env_array) == -1)
		{
			status = error_message(path);
			free_tab(env_array);
			exit(status);
		}
	}
	waitpid(g_sig.pid, &status, 0);
	return (handle_child_result(status, mini));
}
