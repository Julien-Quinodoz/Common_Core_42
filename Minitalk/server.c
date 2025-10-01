/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:29:32 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/23 12:43:30 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	handle_signal(int signal)
{
	static unsigned char	create_char;
	static int				bit_index;

	create_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (create_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", create_char);
		bit_index = 0;
		create_char = 0;
	}
	else
		create_char <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
