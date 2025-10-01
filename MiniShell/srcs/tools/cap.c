/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:05:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 14:15:13 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_command_error(t_parser *parser)
{
	char	c;

	ft_putstr_fd("zsh: command not found: ", 2);
	while (parser->input[parser->position])
	{
		c = parser->input[parser->position];
		if (c == ' ' || c == '\t' || c == '\n'
			|| c == '|' || c == ';' || c == '>' || c == '<')
			break ;
		ft_putchar_fd(c, 2);
		parser->position++;
	}
	ft_putchar_fd('\n', 2);
}

/*
** Checks if the current position is the first word in a command
** Returns 1 if it's the first word, 0 otherwise
*/
static int	is_first_word_in_command(t_parser *parser, int start)
{
	char	c;
	int		is_first_word;

	is_first_word = 1;
	while (start > 0)
	{
		c = parser->input[start - 1];
		if (c == ' ' || c == '\t')
			start--;
		else if (c == '|' || c == ';' || c == '>' || c == '<')
		{
			start--;
			is_first_word = 1;
		}
		else
		{
			is_first_word = 0;
			break ;
		}
	}
	return (is_first_word);
}

/*
** Checks if a command starts with an uppercase letter and handles the error
** Returns 1 if the command is uppercase (invalid), 0 otherwise
*/
int	handle_uppercase_command(t_parser *parser, int start)
{
	char	c;
	int		is_first_word;

	is_first_word = is_first_word_in_command(parser, start);
	if (!is_first_word)
		return (0);
	c = parser->input[start];
	if (ft_isalpha(c) && c >= 'A' && c <= 'Z')
	{
		print_command_error(parser);
		return (1);
	}
	return (0);
}
