/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:40:11 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/14 12:44:45 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_move(t_stack_node **a)
{
	t_stack_node	*smallest;

	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
