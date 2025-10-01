/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:25:00 by rtari-ca          #+#    #+#             */
/*   Updated: 2025/04/09 22:02:32 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handle output redirection (> or >>)
 * 
 * Opens a file for writing in either truncate or append mode
 * and redirects stdout to this file.
 * 
 * @param mini    Shell state structure
 * @param token   Token containing the filename
 * @param type    Redirection type (TRUNC or APPEND)
 */
void	handle_output_redirect(t_mini *mini, t_token *token, int type)
{
	ft_close(mini->fdout);
	if (type == TRUNC)
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (mini->fdout == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		mini->ret = 1;
		mini->no_exec = 1;
		return ;
	}
	dup2(mini->fdout, 1);
}

/**
 * @brief Handle input redirection (<)
 * 
 * Opens a file for reading and redirects stdin to read from this file.
 * 
 * @param mini    Shell state structure
 * @param token   Token containing the filename
 */
void	handle_input_redirect(t_mini *mini, t_token *token)
{
	ft_close(mini->fdin);
	mini->fdin = open(token->str, O_RDONLY, S_IRWXU);
	if (mini->fdin == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		mini->ret = 1;
		mini->no_exec = 1;
		return ;
	}
	dup2(mini->fdin, 0);
}
