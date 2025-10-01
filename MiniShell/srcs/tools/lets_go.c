/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:28:54 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/02 11:01:22 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_lets_go(void)
{
	char	*msg;
	int		i;

	i = 0;
	msg = "⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐\
	 \n  ⭐ ⭐ ⭐  LET'S GO  ⭐ ⭐ ⭐\n⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ ⭐ \n ";
	while (msg[i])
	{
		printf("%c", msg[i]);
		fflush(stdout);
		usleep(5000);
		i++;
	}
}
