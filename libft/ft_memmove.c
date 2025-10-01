/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:35:34 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 15:04:30 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp_src;
	char	*dest;

	tmp_src = (char *)src;
	dest = (char *)dst;
	if (tmp_src < dest)
	{
		while (n--)
			dest[n] = tmp_src[n];
	}
	else
		ft_memcpy(dest, tmp_src, n);
	return (dst);
}
/*
Astuces:
si pas de chevauchement : memcpy
si chevauchement : commencer a copier par la fin pour pas perdre des données

Explication compréhensible:
Memmove fait la même chose que la memcpy
 mais cette fois, la copie est faite, comme dit dans le man, de manière
 non destructive.
  Cela signifie que les deux chaînes (src et dst) peuvent
  se chevaucher en mémoire et que cette fonction n'écrase pas une partie ou
  la totalité de la chaîne lors de la copie.

   Le MAN parle de chevauchement de mémoire:
 copie de S1 dans S2
 S1 commence a copier a partir de la case 4 de S2
 a partire de la case 4 : on retrouvera S1 ...

 VALEUR RENVOYEE : La fonction renvoie un pointeur sur dst.

*/
