/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:25:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/04/18 21:24:37 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

/* Global signal variable */
t_sig	g_sig;

/* Add these external declarations to access readline functions */
extern void		rl_replace_line(const char *text, int clear_undo);
extern int		rl_on_new_line(void);
extern void		rl_redisplay(void);

/* If we're in the shell itself (not in a child process) */
/* Reset readline's state and display a new prompt */
void	handle_sigint(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_sig.exit_status = 1;
	}
	else
	{
		write(1, "\n", 1);
		g_sig.exit_status = 130;
	}
	g_sig.sigint = 1;
}

/* Only act when in a child process
   Do nothing in the parent process - ignore SIGQUIT
   Only display Quit if we're in a child process executing a command
   Do nothing if in parent process/empty prompt */
void	handle_sigquit(int code)
{
	(void)code;
	if (g_sig.pid != 0)
	{
		write(2, "Quit: 3\n", 8);
		g_sig.exit_status = 131;
		g_sig.sigquit = 1;
	}
}

void	initialize_signals(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_status = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
