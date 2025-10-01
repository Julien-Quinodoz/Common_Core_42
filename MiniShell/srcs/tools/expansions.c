/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:54:15 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/17 11:27:33 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_env_var(char *result, int *j, char *arg, t_expand_vars *vars)
{
	int		start;
	char	name[BUFF_SIZE];
	char	*val;

	start = *(vars->i);
	while (arg[*(vars->i)] && (ft_isalnum(arg[*(vars->i)]) || \
			arg[*(vars->i)] == '_'))
		(*(vars->i))++;
	extract_name(name, arg, vars->i, start);
	val = get_env_value(name, vars->env);
	copy_var_to_result(result, j, val);
}

static void	handle_var_exp(char *result, int *j, char *arg, t_expand_vars *vars)
{
	int	*i;

	i = vars->i;
	if (arg[*i] == '?')
		handle_question_mark(result, j, i, vars->ret);
	else if (ft_isalnum(arg[*i]) || arg[*i] == '_')
		handle_env_var(result, j, arg, vars);
	else
		result[(*j)++] = '$';
}

static void	char_with_vars(char *result, int *j, char *arg, t_expand_vars *vars)
{
	int	*i;

	i = vars->i;
	if (arg[*i] == '\'')
	{
		hand_sing_quot(result, j, arg, vars);
		return ;
	}
	if (vars->quotes->in_single)
	{
		cpy_char(result, j, arg, i);
		return ;
	}
	if (arg[*i] == '$' && arg[*i + 1])
	{
		(*i)++;
		handle_var_exp(result, j, arg, vars);
	}
	else
		cpy_char(result, j, arg, i);
}

static int	allocate_expansion_len(const char *arg)
{
	if (!arg)
		return (0);
	return (ft_strlen(arg) * 4 + 1024);
}

char	*expansions(char *arg, t_env *env, int ret)
{
	char			*result;
	int				i;
	int				j;
	t_expand_vars	vars;
	t_quote_state	quotes;

	if (!arg)
		return (NULL);
	result = malloc(sizeof(char) * (allocate_expansion_len(arg) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	quotes.in_single = 0;
	vars.i = &i;
	vars.env = env;
	vars.ret = ret;
	vars.quotes = &quotes;
	while (arg[i])
		char_with_vars(result, &j, arg, &vars);
	result[j] = '\0';
	return (result);
}
