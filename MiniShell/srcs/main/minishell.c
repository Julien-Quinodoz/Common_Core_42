/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:14:08 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/18 21:12:19 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_and_get_exit_status(t_mini *mini)
{
	int		status;
	pid_t	wait_pid;

	status = 0;
	wait_pid = waitpid(-1, &status, 0);
	while (wait_pid > 0)
	{
		if (WIFEXITED(status))
			mini->ret = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			mini->ret = 128 + WTERMSIG(status);
		wait_pid = waitpid(-1, &status, 0);
	}
}

static void	handle_parent_process(t_mini *mini)
{
	dup2(mini->in, STDIN_FILENO);
	dup2(mini->out, STDOUT_FILENO);
	reset_std(mini);
	wait_and_get_exit_status(mini);
	close_fds(mini);
	reset_fds(mini);
}

static void	handle_child_process(t_mini *mini)
{
	free_token(mini->start);
	exit(mini->ret);
}

/* Find the next semicolon or end of tokens */
/* Skip to end of current command (either semicolon or end of list) */
/* If we found a semicolon (END), get next token */
static t_token	*get_next_token(t_token *token)
{
	t_token	*next;

	next = token;
	while (next && next->next && next->type != END)
		next = next->next;
	if (next && next->type == END)
	{
		if (next->next)
			return (next->next);
	}
	return (NULL);
}

void	minishell(t_mini *mini)
{
	t_token	*token;

	token = next_run(mini->start, NOSKIP);
	if (is_t(mini->start, "TAI"))
		token = mini->start->next;
	while (token)
	{
		if (mini->exit != 0)
			break ;
		init_mini_sh(mini);
		process_redirections_and_execute(mini, token);
		if (mini->parent == 1)
			handle_parent_process(mini);
		if (mini->parent == 0)
			handle_child_process(mini);
		mini->no_exec = 0;
		token = get_next_token(token);
	}
}
