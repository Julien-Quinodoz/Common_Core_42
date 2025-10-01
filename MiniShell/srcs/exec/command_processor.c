/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:38:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 15:45:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_command_execution(char **cmd, t_mini *mini, t_token *token)
{
	int	status;
	int	is_quoted;

	status = mini->ret;
	if (!cmd || !cmd[0])
		return (status);
	is_quoted = (cmd[0][0] == '\'' || cmd[0][0] == '\"');
	if (is_quoted || cmd[0][0] == '$')
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(cmd[0], STDERR);
		ft_putendl_fd(": command not found", STDERR);
		status = UNKNOWN_COMMAND;
	}
	else if (strcmp(cmd[0], "exit") == 0 && !has_type(token, PIPE))
		mini_exit(mini, cmd);
	else if (verify_builtin(cmd[0]))
		status = execute_builtin(cmd, mini);
	else
		status = execute_external(cmd, mini->env, mini);
	return (status);
}

/* Only close non-standard file descriptors */
/* Exit child processes immediately */

static void	execute_command(t_mini *mini, t_token *token, char **cmd)
{
	expand_args(cmd, mini);
	mini->ret = handle_command_execution(cmd, mini, token);
	free_tab(cmd);
	if (mini->pipin > 2)
	{
		close(mini->pipin);
		mini->pipin = -1;
	}
	if (mini->pipout > 2)
	{
		close(mini->pipout);
		mini->pipout = -1;
	}
	mini->charge = 0;
	if (mini->parent == 0)
	{
		exit(mini->ret);
	}
}

void	process_command(t_mini *mini, t_token *token)
{
	char	**cmd;

	if (mini->charge == 0)
		return ;
	cmd = create_command_array(token);
	if (!cmd)
		return ;
	execute_command(mini, token, cmd);
}
