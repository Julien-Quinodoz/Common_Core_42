/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:22:15 by rodrigo           #+#    #+#             */
/*   Updated: 2025/04/16 23:00:10 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* Handle special command error message and return value */
static int	handle_dollar_variable(t_mini *mini, char *line)
{
	char	*value;
	char	*var_name;

	var_name = ft_strdup(line + 1);
	value = get_env_value(var_name, mini->env);
	free(var_name);
	if (value)
	{
		ft_putendl_fd(value, 1);
		free(value);
		return (1);
	}
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(line, STDERR);
	ft_putendl_fd(": command not found", STDERR);
	mini->ret = UNKNOWN_COMMAND;
	return (1);
}

int	handle_special_command(t_mini *mini, char *line)
{
	if (!line)
		return (0);
	if (handle_quoted_variable(mini, line))
		return (1);
	if (ft_strcmp(line, "$$") == 0)
	{
		ft_putstr_fd("minishell: $$: command not found\n", 2);
		mini->ret = UNKNOWN_COMMAND;
		return (1);
	}
	if (line[0] == '$' && line[1] != '\0')
		return (handle_dollar_variable(mini, line));
	if (ft_strcmp(line, "\"$\"") == 0 || ft_strcmp(line, "'$'") == 0 || \
	ft_strcmp(line, "$") == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd(": command not found\n", 2);
		mini->ret = UNKNOWN_COMMAND;
		return (1);
	}
	return (0);
}

/* Validates token syntax to catch invalid sequences
// Check if there's a command after pip
// Check if there's a filename after redirection
// Check if this is the first token (no valid command before redirection)*/
static int	handle_pipe_syntax(t_token *current)
{
	t_token	*next;

	next = current->next;
	if (!next || next->type != CMD)
	{
		ft_putstr_fd("minishell: syntax error `|'\n", 2);
		return (1);
	}
	return (0);
}

static int	handle_redirection_syntax(t_token *current)
{
	t_token	*next;
	t_token	*prev;

	next = current->next;
	if (!next)
	{
		ft_putstr_fd("minishell: syntax error `newline'\n", 2);
		return (1);
	}
	prev = current->prev;
	if (!prev || (prev->type != CMD && prev->type != ARG))
	{
		ft_putstr_fd("minishell: syntax error near  `", 2);
		if (current->type == TRUNC)
			ft_putstr_fd(">", 2);
		else if (current->type == APPEND)
			ft_putstr_fd(">>", 2);
		else if (current->type == INPUT)
			ft_putstr_fd("<", 2);
		else
			ft_putstr_fd("<<", 2);
		ft_putstr_fd("'\n", 2);
		return (1);
	}
	return (0);
}

int	validate_token_syntax(t_token *tokens)
{
	t_token	*current;

	if (!tokens)
		return (0);
	current = tokens;
	while (current)
	{
		if (current->type == PIPE)
		{
			if (handle_pipe_syntax(current))
				return (1);
		}
		else if (current->type == TRUNC || current->type == INPUT || \
				current->type == APPEND || current->type == HEREDOC)
		{
			if (handle_redirection_syntax(current))
				return (1);
		}
		current = current->next;
	}
	return (0);
}
