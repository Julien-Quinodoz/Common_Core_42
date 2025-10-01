/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:21 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/18 11:59:01 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_parser_error(t_parser_token *tokens, t_mini *mini)
{
	t_parser_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_ERROR)
		{
			mini->ret = 258;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

static void	free_invalid_tokens(t_token *start)
{
	t_token	*next;

	while (start)
	{
		next = start->next;
		free(start->str);
		free(start);
		start = next;
	}
}

static void	handle_valid_tokens(t_mini *mini, t_parser_token *tokens)
{
	mini->start = convert_to_mini_tokens(tokens);
	if (mini->start && validate_token_syntax(mini->start))
	{
		mini->ret = 258;
		free_invalid_tokens(mini->start);
		mini->start = NULL;
	}
}

void	create_tokens(t_mini *mini, char *line)
{
	t_parser		*parser;
	t_parser_token	*tokens;
	int				has_error;

	parser = parser_init_with_env(line, mini->env);
	if (!parser)
	{
		free(line);
		return ;
	}
	tokens = parser_parse_command(parser);
	has_error = has_parser_error(tokens, mini);
	if (!has_error)
		handle_valid_tokens(mini, tokens);
	else
		mini->start = NULL;
	free_parser_tokens(tokens);
	parser_free(parser);
	free(line);
}
