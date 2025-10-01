/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:54:15 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 14:20:42 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansions(char *arg, t_env *env, int ret)
{
	char			*result;
	int				i;
	int				j;
	t_expand_vars	vars;

	if (!arg)
		return (NULL);
	reset_quote_state();
	result = malloc(sizeof(char) * (allocate_expansion_len(arg) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	vars.i = &i;
	vars.env = env;
	vars.ret = ret;
	while (arg[i])
		process_char_with_vars(result, &j, arg, &vars);
	result[j] = '\0';
	return (result);
}
