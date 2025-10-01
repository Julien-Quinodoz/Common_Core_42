/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_putnbr_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:03:27 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/23 10:13:21 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptf_putnbr_hexa(unsigned long nbr, char up)
{
	int		len;
	int		mod;
	char	*base;
	int		aux;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		aux = ft_ptf_putnbr_hexa((nbr / 16), up);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	mod = nbr % 16;
	if (write(1, &base[mod], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
