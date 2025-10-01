/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:30:32 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 18:04:34 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_type(t_token *token, int type)
{
	if (token && token->type == type)
		return (1);
	else
		return (0);
}

int	is_t(t_token *token, char *types)
{
	if (ft_strchr(types, ' ') && is_type(token, EMPTY))
		return (1);
	else if (ft_strchr(types, 'X') && is_type(token, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && is_type(token, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && is_type(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && is_type(token, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && is_type(token, PIPE))
		return (1);
	else if (ft_strchr(types, 'E') && is_type(token, END))
		return (1);
	else if (ft_strchr(types, 'H') && is_type(token, HEREDOC))
		return (1);
	return (0);
}

/* Checks if a token or its linked list contains a specific type.
 * Special case: If type is PIPE, it will check for a pipe before END.
 * Returns 1 if found, 0 otherwise.
 * Also provides has_pipe functionality when called with PIPE type.
 */
int	has_type(t_token *token, int type)
{
	int	end_check;

	if (!token)
		return (0);
	if (type == PIPE)
		end_check = 0;
	else
		end_check = 1;
	while (token && (end_check || is_type(token, END) == 0))
	{
		if (is_type(token, type))
			return (1);
		token = token->next;
	}
	return (0);
}

t_token	*next_type(t_token *token, int type, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type != type)
		token = token->next;
	return (token);
}

/* Case-insensitive string comparison */
int	str_case_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (ft_tolower(s1[i]) == ft_tolower(s2[i])))
		i++;
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
}
