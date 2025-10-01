/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:37:42 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 15:11:06 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dst == 0 && src == 0)
		return (dst);
	tmp_dest = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
		n--;
	}
	return (dst);
}
/*
Explication compréhensible

La fonction copie un maximum de n octets de  src  vers zone memoir dst.
 les deux zone ne doive pas se chevaucher!
 si c'est le cas , utilisez plustot ft_memmove ou des temporaires tmp

 Le MAN parle de chevauchement de mémoire:
 copie de S1 dans S2
 S1 commence a copier a partir de la case 4 de S2
 a partire de la case 4 : on retrouvera S1 ...


nous avons  besoin de pointeurs temporaires
pour manipuler les données.

Cette fonction fonctionne comme la strcpy , sauf qu'elle
memcpy accepte void * comme paramètres, nous pouvons donc lui donner n'importe
quel type de pointeur que nous voulons copier.
VALEUR RENVOYEE : La fonction memcpy() renvoie un pointeur sur dest
*/
