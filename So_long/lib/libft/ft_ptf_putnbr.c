/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:02:16 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/23 10:13:43 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptf_putnbr(long nb)
{
	long		num;
	int			i;
	int			aux;

	i = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		i += 1;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb > 9)
	{
		aux = ft_ptf_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		i += aux;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	i += 1;
	return (i);
}
