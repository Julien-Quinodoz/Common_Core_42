/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:00:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 13:37:58 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_word_char(t_parser *parser, char *quote)
{
	if (!*quote && (parser->input[parser->position] == '|'
			|| parser->input[parser->position] == '>'
			|| parser->input[parser->position] == '<'
			|| parser->input[parser->position] == ';'
			|| parser->input[parser->position] == ' '))
		return (0);
	if ((parser->input[parser->position] == '\''
			|| parser->input[parser->position] == '\"') && !*quote)
		*quote = parser->input[parser->position];
	else if (parser->input[parser->position] == *quote)
		*quote = 0;
	parser->position++;
	return (1);
}

t_parser_token	*handle_word(t_parser *parser)
{
	int		start;
	int		len;
	char	quote;

	start = parser->position;
	len = 0;
	quote = 0;
	if (handle_uppercase_command(parser, start))
		return (NULL);
	while (parser->input[parser->position])
	{
		if (!process_word_char(parser, &quote))
			break ;
		len++;
	}
	return (extract_word_value(parser, start, len));
}

static t_parser_token	*create_unquoted_token(char *value, int len)
{
	char			*temp;
	t_parser_token	*token;

	temp = ft_substr(value, 1, len - 2);
	if (!temp)
		return (NULL);
	token = create_token(TOKEN_WORD, temp);
	if (!token)
	{
		free(temp);
		return (NULL);
	}
	free(value);
	return (token);
}

static t_parser_token	*process_quoted_word(char *value, int len)
{
	int				preserve_quotes;

	if (len < 2)
		return (create_token(TOKEN_WORD, value));
	preserve_quotes = (value[0] == '\'' && value[len - 1] == '\'');
	if (preserve_quotes)
		return (create_token(TOKEN_WORD, value));
	return (create_unquoted_token(value, len));
}

t_parser_token	*extract_word_value(t_parser *parser, int start, int len)
{
	char	*value;

	if (len == 0 || start < 0 || (size_t)start >= ft_strlen(parser->input))
		return (NULL);
	value = ft_substr(parser->input, start, len);
	if (!value)
		return (NULL);
	if (len >= 2 && ((value[0] == '\'' && value[len - 1] == '\'') || \
			(value[0] == '\"' && value[len - 1] == '\"')))
		return (process_quoted_word(value, len));
	return (process_word_token(parser, value));
}
