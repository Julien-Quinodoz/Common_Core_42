/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:49:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:52 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Function prototypes from other redirection files */
void	handle_output_redirect(t_mini *mini, t_token *token, int type);
void	handle_input_redirect(t_mini *mini, t_token *token);
int		setup_pipe(t_mini *mini);
int		handle_heredoc(t_mini *mini, t_token *delimiter);

/* Define HEREDOC constant if not defined */
#ifndef HEREDOC
# define HEREDOC 8
#endif

/*If this is the parent process after a pipe setup,
		 create a helper file descriptor to track pipes */
static int	handle_output_redirections(t_mini *mini, t_token *token, int type)
{
	int	pipe_status;

	if (type == TRUNC || type == APPEND)
		handle_output_redirect(mini, token, type);
	else if (type == INPUT)
		handle_input_redirect(mini, token);
	else if (type == HEREDOC)
		handle_heredoc(mini, token);
	else if (type == PIPE)
	{
		pipe_status = setup_pipe(mini);
		return (pipe_status);
	}
	return (0);
}

/**
 * @brief Setup redirections and execute command based on token type
 *
 * Analyzes the token type and sets up appropriate redirections:
 * - TRUNC (>): Output redirection with truncation
 * - APPEND (>>): Output redirection with append
 * - INPUT (<): Input redirection
 * - HEREDOC (<<): Heredoc input
 * - PIPE (|): Pipe between commands
 *
 * @param mini    Shell state structure
 * @param token   Token to process
 * @param type    Type of redirection
 * @return int    Status code (1 for parent process, 2 for child process in pipe)
 */
int	setup_redirections(t_mini *mini, t_token *token, int type)
{
	int	pipe_status;

	pipe_status = handle_output_redirections(mini, token, type);
	return (pipe_status);
}

static int	handle_prev_token(t_mini *mini, t_token *token, t_token *prev)
{
	int	pipe_status;

	pipe_status = 0;
	if (is_type(prev, TRUNC))
		pipe_status = setup_redirections(mini, token, TRUNC);
	else if (is_type(prev, APPEND))
		pipe_status = setup_redirections(mini, token, APPEND);
	else if (is_type(prev, INPUT))
		pipe_status = setup_redirections(mini, token, INPUT);
	else if (is_type(prev, HEREDOC))
		pipe_status = setup_redirections(mini, token, HEREDOC);
	else if (is_type(prev, PIPE))
		pipe_status = setup_redirections(mini, token, PIPE);
	return (pipe_status);
}

static void	execute_if_needed(t_mini *mini, t_token *token,
		t_token *prev, int pipe_status)
{
	if ((is_type(prev, END) || is_type(prev, PIPE) || !prev)
		&& pipe_status != 1 && mini->no_exec == 0)
		process_command(mini, token);
}

void	process_redirections_and_execute(t_mini *mini, t_token *token)
{
	t_token	*prev;
	t_token	*next;
	int		pipe_status;

	prev = prev_sep(token, NOSKIP);
	next = next_sep(token, NOSKIP);
	pipe_status = handle_prev_token(mini, token, prev);
	if (next && is_type(next, END) == 0 && pipe_status != 1)
	{
		process_redirections_and_execute(mini, next->next);
	}
	execute_if_needed(mini, token, prev, pipe_status);
}
