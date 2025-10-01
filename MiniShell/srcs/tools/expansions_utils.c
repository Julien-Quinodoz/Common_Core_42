/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:20:37 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/17 11:28:43 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hand_sing_quot(char *result, int *j, char *arg, t_expand_vars *vars)
{
	vars->quotes->in_single = !vars->quotes->in_single;
	result[(*j)++] = arg[(*vars->i)++];
}

void	cpy_char(char *result, int *j, char *arg, int *i)
{
	result[(*j)++] = arg[(*i)++];
}

void	extract_name(char *name, char *arg, int *i, int start)
{
	int	k;
	int	len;

	len = *i - start;
	k = 0;
	while (k < len && k < BUFF_SIZE - 1)
	{
		name[k] = arg[start + k];
		k++;
	}
	name[k] = '\0';
}

void	handle_question_mark(char *result, int *j, int *i, int ret)
{
	char	*val;
	int		k;

	val = ft_itoa(ret);
	k = 0;
	while (val && val[k])
		result[(*j)++] = val[k++];
	free(val);
	(*i)++;
}

void	copy_var_to_result(char *result, int *j, char *val)
{
	int	k;

	k = 0;
	while (val && val[k])
		result[(*j)++] = val[k++];
	free(val);
}
