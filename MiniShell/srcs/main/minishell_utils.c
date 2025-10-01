/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:28:25 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/18 21:12:04 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Modified parse function that provides a cleaner prompt with correct newlines
  	Add a newline when receiving EOF (Ctrl-D)
	 Don't process empty lines */
void	custom_parse(t_mini *mini)
{
	char	*line;
	int		special_cmd_result;

	line = readline("minishell> ");
	if (!line)
	{
		write(STDOUT_FILENO, "\n", 1);
		mini->exit = 1;
		return ;
	}
	if (!*line)
	{
		free(line);
		return ;
	}
	if (*line)
		add_history(line);
	special_cmd_result = handle_special_command(mini, line);
	if (special_cmd_result)
	{
		free(line);
		return ;
	}
	create_tokens(mini, line);
}

/**
 * @brief Compatibility wrapper for process_redirections_and_execute
 *
 * This is kept for backward compatibility with the existing code.
 * New code should use process_redirections_and_execute directly.
 */
void	redir_and_exec(t_mini *mini, t_token *token)
{
	process_redirections_and_execute(mini, token);
}

void	init_mini_sh(t_mini *mini)
{
	mini->charge = 1;
	mini->parent = 1;
	mini->last = 1;
}
