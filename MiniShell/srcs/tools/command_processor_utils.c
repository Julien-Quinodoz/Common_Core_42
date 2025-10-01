/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processor_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:44:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/16 23:07:44 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	calculate_args_count(t_token *start)
{
	t_token	*current;
	int		count;

	if (!start)
		return (0);
	current = start->next;
	count = 2;
	while (current && current->type < TRUNC)
	{
		current = current->next;
		count++;
	}
	return (count);
}

char	**construct_command_array(t_token *start, int size)
{
	t_token	*current;
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * size);
	if (!array)
		return (NULL);
	current = start->next;
	array[0] = ft_strdup(start->str);
	i = 1;
	while (current && current->type < TRUNC)
	{
		array[i++] = ft_strdup(current->str);
		current = current->next;
	}
	array[i] = NULL;
	return (array);
}

char	**create_command_array(t_token *start)
{
	int	size;

	if (!start)
		return (NULL);
	size = calculate_args_count(start);
	return (construct_command_array(start, size));
}
