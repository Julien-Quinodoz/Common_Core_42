/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:30:00 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 14:18:43 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_quotes(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == '\'' || str[i] == '\"'))
		i++;
	return (!str[i]);
}

int	count_consecutive_quotes(const char *str, int start)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[start + count] && (str[start + count] == '\''
			|| str[start + count] == '\"'))
		count++;
	return (count);
}

static int	check_dollar_at_end(char *line, int quote_count)
{
	if (quote_count > 0 && line[quote_count] == '$'
		&& !line[quote_count + 1])
		return (1);
	if (ft_strcmp(line, "\"$\"") == 0 || ft_strcmp(line, "'$'") == 0)
		return (1);
	return (0);
}

char	*handle_quoted_dollar(t_mini *mini, char *line)
{
	int		quote_count;
	char	*result;

	(void)mini;
	if (!line)
		return (NULL);
	quote_count = count_consecutive_quotes(line, 0);
	if (check_dollar_at_end(line, quote_count))
		return (ft_strdup("$"));
	if (ft_strchr(line, '$'))
		return (NULL);
	result = ft_strdup(line);
	return (result);
}

int	handle_quoted_variable(t_mini *mini, char *line)
{
	char	*unquoted;
	char	*expanded;

	if (!(line[0] == '\"' && line[strlen(line)-1] == '\"' && strchr(line, '$')))
		return (0);
	unquoted = ft_substr(line, 1, ft_strlen(line) - 2);
	if (!unquoted)
		return (0);
	expanded = expansions(unquoted, mini->env, mini->ret);
	free(unquoted);
	if (!expanded)
		return (0);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(expanded, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(expanded);
	mini->ret = UNKNOWN_COMMAND;
	return (1);
}
