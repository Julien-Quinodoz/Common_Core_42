/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:00:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/04/10 22:54:49 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	show_eof_warning(char *delimiter, int pipe_fd)
{
	ft_putstr_fd("minishell: warning: here-document delimited ", 2);
	ft_putstr_fd("by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
	close(pipe_fd);
	return (1);
}

static int	handle_heredoc_line(t_mini *mini, int *pipe_fd,
		char *delimiter, int *original_stdin)
{
	char	*line;

	ft_putstr_fd("> ", 1);
	line = readline("");
	if (!line)
	{
		show_eof_warning(delimiter, pipe_fd[1]);
		mini->fdin = pipe_fd[0];
		close(*original_stdin);
		return (1);
	}
	if (ft_strcmp(line, delimiter) == 0)
	{
		free(line);
		return (1);
	}
	ft_putstr_fd(line, pipe_fd[1]);
	ft_putstr_fd("\n", pipe_fd[1]);
	free(line);
	return (0);
}

static int	setup_pipe_and_stdin(int *pipe_fd, int *original_stdin)
{
	if (pipe(pipe_fd) == -1)
		return (1);
	*original_stdin = dup(STDIN_FILENO);
	if (*original_stdin == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (1);
	}
	return (0);
}

static int	read_heredoc_content(t_mini *mini, char *delimiter,
		int *pipe_fd, int original_stdin)
{
	while (!handle_heredoc_line(mini, pipe_fd, delimiter, &original_stdin))
		;
	close(pipe_fd[1]);
	if (mini->fdin != STDIN_FILENO)
		close(mini->fdin);
	mini->fdin = pipe_fd[0];
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (0);
}

int	handle_heredoc(t_mini *mini, t_token *token)
{
	int	pipe_fd[2];
	int	original_stdin;

	if (setup_pipe_and_stdin(pipe_fd, &original_stdin))
		return (1);
	return (read_heredoc_content(mini, token->str, pipe_fd, original_stdin));
}
