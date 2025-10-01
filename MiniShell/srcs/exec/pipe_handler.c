/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:30:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/04/16 12:29:35 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

/* Sets up child process for pipe: redirects its STDIN from pipe read end. */
/* Example: For `ls | wc`, this function configures the `wc` process.      */
static void	handle_child_process(int *pipefd, t_mini *mini)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	mini->pipin = pipefd[0];
	mini->pid = -1;
	mini->parent = 0;
	mini->no_exec = 0;
}

/* Sets up parent process for pipe: redirects its STDOUT to pipe write end. */
/* Example: For `ls | wc`, this function configures the `ls` process.       */
static void	handle_parent_process(int *pipefd, t_mini *mini, pid_t pid)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	mini->pipout = pipefd[1];
	mini->pid = pid;
	mini->last = 0;
}

/* Creates a pipe and forks. Returns 1 on success, 0 on failure. */
/* Example: Called by setup_pipe before configuring parent/child. */
	/* Remove this line causing the error */
	/* pipefd[0], pipefd[1]); */
static int	create_pipe_and_fork(int *pipefd, pid_t *pid)
{
	if (pipe(pipefd) == -1)
	{
		return (0);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (0);
	}
	return (1);
}

/* Creates pipe, forks, configures I/O redirection for parent & child. */
/* Returns 1 (parent), 2 (child), or 0 (error).                      */
/* Example: Called for `cmd1 | cmd2` to set up the pipe and processes. */
int	setup_pipe(t_mini *mini)
{
	pid_t	pid;
	int		pipefd[2];

	if (!create_pipe_and_fork(pipefd, &pid))
		return (0);
	if (pid == 0)
	{
		handle_child_process(pipefd, mini);
		return (2);
	}
	else
	{
		handle_parent_process(pipefd, mini, pid);
		return (1);
	}
}
