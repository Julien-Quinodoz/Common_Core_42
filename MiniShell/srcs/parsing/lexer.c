/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:02 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/18 11:54:53 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Identifies shell tokens and builds appropriate token structures */
	/**
	char		*expanded;
	int			in_single_quotes;

	if (type == TOKEN_WORD && parser->env && value && ft_strchr(value, '$'))
	{
		in_single_quotes = 0;
		if (value[0] == '\'')
			in_single_quotes = 1;
		if (!in_single_quotes)
		{
			expanded = expand_env_vars(value, parser->env);
			free(value);
			value = expanded;
		}
	}**/
static t_parser_token	*build_token(t_parser *parser, int type, char *value)
{
	(void)parser;
	return (create_token(type, value));
}

/* Processes special shell operators like >>, >, <, |, ; */
static t_parser_token	*handle_special_char(t_parser *parser)
{
	char	current;
	char	next;

	current = parser->input[parser->position];
	next = parser->input[parser->position + 1];
	if (current == '>' || current == '<')
		return (handle_redirects(parser, current));
	else if (current == '|')
	{
		if (next == '|')
		{
			ft_putstr_fd("minishell: syntax error `||'\n", 2);
			parser->position += 2;
			return (build_token(parser, TOKEN_ERROR, NULL));
		}
		parser->position++;
		return (build_token(parser, TOKEN_PIPE, ft_strdup("|")));
	}
	else if (current == ';')
	{
		parser->position++;
		return (build_token(parser, TOKEN_SEMICOLON, ft_strdup(";")));
	}
	return (NULL);
}

static t_parser_token	*handle_initial_redirection(t_parser *parser)
{
	if (parser->position == 0 && (parser->input[parser->position] == '>' \
		|| parser->input[parser->position] == '<'))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (parser->input[parser->position] == '>' && \
			parser->input[parser->position + 1] == '>')
			ft_putstr_fd(">>", 2);
		else if (parser->input[parser->position] == '<' && \
			parser->input[parser->position + 1] == '<')
			ft_putstr_fd("<<", 2);
		else if (parser->input[parser->position] == '>')
			ft_putstr_fd(">", 2);
		else
			ft_putstr_fd("<", 2);
		ft_putstr_fd("'\n", 2);
		if ((parser->input[parser->position] == '>' && \
			parser->input[parser->position + 1] == '>') || \
			(parser->input[parser->position] == '<' && \
				parser->input[parser->position + 1] == '<'))
			parser->position += 2;
		else
			parser->position++;
		return (build_token(parser, TOKEN_ERROR, NULL));
	}
	return (NULL);
}

t_parser_token	*lexer_get_next_token(t_parser *parser)
{
	t_parser_token	*token;

	lexer_skip_whitespace(parser);
	if (!parser->input[parser->position])
		return (build_token(parser, TOKEN_EOF, NULL));
	token = handle_initial_redirection(parser);
	if (token)
		return (token);
	if (parser->input[parser->position] == '|'
		|| parser->input[parser->position] == '>'
		|| parser->input[parser->position] == '<'
		|| parser->input[parser->position] == ';')
		return (handle_special_char(parser));
	return (handle_word(parser));
}
