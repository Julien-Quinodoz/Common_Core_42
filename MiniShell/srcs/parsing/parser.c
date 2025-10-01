/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:11:02 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 17:18:29 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

/* Creates and initializes a new parser with the given input string */
t_parser	*parser_init(char *input)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->input = input;
	parser->position = 0;
	parser->current_token = NULL;
	parser->env = NULL;
	return (parser);
}

/* Creates a parser with environment variables for expansion */
t_parser	*parser_init_with_env(char *input, t_env *env)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->input = input;
	parser->position = 0;
	parser->current_token = NULL;
	parser->env = env;
	return (parser);
}

/* Cleans up parser and token memory to prevent leaks */
void	parser_free(t_parser *parser)
{
	t_parser_token	*current;
	t_parser_token	*next;

	if (!parser)
		return ;
	current = parser->current_token;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	free(parser);
}

/* Free parser tokens to prevent memory leaks */
void	free_parser_tokens(t_parser_token *tokens)
{
	t_parser_token	*current;
	t_parser_token	*next;

	current = tokens;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}

/* Main parsing function that processes input line
  // Original parse implementation - not used anymore
    // We now use custom_parse in minishell.c instead */
void	parse(t_mini *mini)
{
	char	*line;
	int		special_cmd_result;

	line = readline("minishell> ");
	if (!line)
	{
		mini->exit = 1;
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
