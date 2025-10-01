/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:01:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 17:18:05 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_skip_whitespace(t_parser *parser)
{
	while (parser->input[parser->position] != '\0'
		&& (parser->input[parser->position] == ' '
			|| parser->input[parser->position] == '\t'))
		parser->position++;
}

t_parser_token	*create_token(t_token_type type, char *value)
{
	t_parser_token	*token;

	token = malloc(sizeof(t_parser_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

char	*expand_env_vars(const char *str, t_env *env)
{
	char	*result;

	if (!str)
		return (NULL);
	result = expansions((char *)str, env, 0);
	return (result);
}

/* Convert parser token type to mini token type */
int	convert_token_type(t_token_type type)
{
	if (type == TOKEN_WORD)
		return (CMD);
	else if (type == TOKEN_PIPE)
		return (PIPE);
	else if (type == TOKEN_REDIRECT_IN)
		return (INPUT);
	else if (type == TOKEN_REDIRECT_OUT)
		return (TRUNC);
	else if (type == TOKEN_REDIRECT_APPEND)
		return (APPEND);
	else if (type == TOKEN_HEREDOC)
		return (HEREDOC);
	else if (type == TOKEN_SEMICOLON)
		return (END);
	else if (type == TOKEN_ERROR)
		return (-1);
	return (ARG);
}
