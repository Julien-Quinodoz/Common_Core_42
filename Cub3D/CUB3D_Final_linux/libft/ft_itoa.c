/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:58:28 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/17 15:45:01 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nb;
	char	*result;

	len = len_int(n);
	nb = n;
	if (n < 0)
		nb *= -1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nb == 0)
		result[0] = '0';
	else
	{
		while (len--, nb != 0)
		{
			result[len] = (nb % 10) + '0';
			nb = (nb - (nb % 10)) / 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}
/*
int  to  Ascii
Alloue (avec malloc) et renvoie une chaîne représentant
l'entier reçu en argument.
Les nombres négatifs doivent être gérés.
*/
