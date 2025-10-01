/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:05:06 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/23 10:12:59 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptf_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (ft_ptf_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_ptf_putnbr_hexa((unsigned long)ptr, 'x');
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}
