/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/14 20:43:37 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Extract environment variable name from a string
** Returns a newly allocated string with the name
*/
char	*extract_env_name(const char *str)
{
	int		i;
	char	*name;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i == 0)
		return (NULL);
	name = ft_substr(str, 0, i);
	return (name);
}

/*
** Check if a character is valid in an environment variable name
*/
int	is_valid_env_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

/*
** Get the length of an environment variable name
*/
int	get_env_name_len(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && is_valid_env_char(str[i]))
		i++;
	return (i);
}
