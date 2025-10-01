/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:00:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 17:17:18 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Parses a complete shell command into a linked list of tokens */
t_parser_token	*parser_parse_command(t_parser *parser)
{
	t_parser_token	*head;
	t_parser_token	*current;
	t_parser_token	*token;

	head = NULL;
	current = NULL;
	while (1)
	{
		token = lexer_get_next_token(parser);
		if (!token || token->type == TOKEN_EOF)
		{
			if (token)
				free(token);
			break ;
		}
		if (!head)
			head = token;
		else
			current->next = token;
		current = token;
	}
	return (head);
}

/* Process token to determine if it's a command or argument */
static void	process_token_type(t_token *new_token, t_parser_token *p_current,
								int *is_first_word)
{
	if (p_current->type != TOKEN_WORD)
		new_token->type = convert_token_type(p_current->type);
	else if (*is_first_word)
	{
		new_token->type = CMD;
		*is_first_word = 0;
	}
	else
		new_token->type = ARG;
	if (p_current->type == TOKEN_PIPE || p_current->type == TOKEN_SEMICOLON)
		*is_first_word = 1;
}

/* Create new token and set up linked list connections */
static t_token	*create_and_link_token(t_token *current,
									t_parser_token *p_current,
									int *is_first_word)
{
	t_token	*new_token;

	if (!p_current || !p_current->value || p_current->type == TOKEN_ERROR)
		return (NULL);
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->str = ft_strdup(p_current->value);
	if (!new_token->str)
	{
		free(new_token);
		return (NULL);
	}
	process_token_type(new_token, p_current, is_first_word);
	new_token->next = NULL;
	new_token->prev = current;
	if (current)
		current->next = new_token;
	return (new_token);
}

/* Convert parser tokens to mini tokens */
t_token	*convert_to_mini_tokens(t_parser_token *parser_tokens)
{
	t_token			*head;
	t_token			*current;
	t_token			*new_token;
	t_parser_token	*p_current;
	int				is_first_word;

	head = NULL;
	current = NULL;
	p_current = parser_tokens;
	is_first_word = 1;
	while (p_current)
	{
		new_token = create_and_link_token(current, p_current, &is_first_word);
		if (!new_token)
			return (NULL);
		if (!head)
			head = new_token;
		current = new_token;
		p_current = p_current->next;
	}
	return (head);
}
