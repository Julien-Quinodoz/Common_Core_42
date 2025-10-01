/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:08:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/14 23:28:22 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_token	*process_word_token(t_parser *parser, char *value)
{
	(void)parser;
	return (create_token(TOKEN_WORD, value));
}

t_parser_token	*handle_redirects(t_parser *parser, char current)
{
	char	next;

	next = parser->input[parser->position + 1];
	if (current == '>' && next == '>')
	{
		parser->position += 2;
		return (create_token(TOKEN_REDIRECT_APPEND, ft_strdup(">>")));
	}
	else if (current == '<' && next == '<')
	{
		parser->position += 2;
		return (create_token(TOKEN_HEREDOC, ft_strdup("<<")));
	}
	else if (current == '>')
	{
		parser->position++;
		return (create_token(TOKEN_REDIRECT_OUT, ft_strdup(">")));
	}
	else if (current == '<')
	{
		parser->position++;
		return (create_token(TOKEN_REDIRECT_IN, ft_strdup("<")));
	}
	return (NULL);
}
