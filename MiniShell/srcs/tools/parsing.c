/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:30:16 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/16 14:27:22 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quotes(char *line, int index)
{
	int	i;
	int	open;
	int	escaped;

	i = 0;
	open = 0;
	while (line[i] && i != index)
	{
		escaped = (i > 0 && line[i - 1] == '\\');
		if (!escaped)
		{
			if (open == 0 && line[i] == '\"')
				open = 1;
			else if (open == 0 && line[i] == '\'')
				open = 2;
			else if (open == 1 && line[i] == '\"')
				open = 0;
			else if (open == 2 && line[i] == '\'')
				open = 0;
		}
		i++;
	}
	return (open);
}

int	is_last_valid_arg(t_token *token)
{
	t_token	*prev;

	if (!token || is_type(token, CMD) || is_type(token, ARG))
	{
		prev = prev_sep(token, NOSKIP);
		if (!prev || is_type(prev, END) || is_type(prev, PIPE))
			return (1);
		return (0);
	}
	else
		return (0);
}

static int	check_dollar_command(t_mini *mini, t_token *token)
{
	t_token	*first;

	first = token;
	while (first && first->type != CMD)
		first = first->next;
	if (first && first->str && first->str[0] == '$')
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(first->str, STDERR);
		ft_putendl_fd(": command not found", STDERR);
		mini->ret = UNKNOWN_COMMAND;
		return (0);
	}
	return (1);
}

static int	handle_syntax_error(t_mini *mini, t_token *token)
{
	if (is_t(token, "TAI") && (!token->next || is_t(token->next, "TAIPE")))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
		if (token->next)
			ft_putstr_fd(token->next->str, STDERR);
		else
			ft_putstr_fd("newline", STDERR);
		ft_putendl_fd("'", STDERR);
		mini->ret = 258;
		return (0);
	}
	if (is_t(token, "PE") && (!token->prev || !token->next
			|| is_t(token->prev, "TAIPE")))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd("'", STDERR);
		mini->ret = 258;
		return (0);
	}
	return (1);
}

int	check_line(t_mini *mini, t_token *token)
{
	if (!check_dollar_command(mini, token))
		return (0);
	while (token)
	{
		if (!handle_syntax_error(mini, token))
			return (0);
		token = token->next;
	}
	return (1);
}
