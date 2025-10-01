/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:36 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 16:20:24 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
Explication compréhensible
la fonction compare les chaînes d'octets. Son fonctionnement est similaire
à celui de la fonction strncmp().

La différence est que ellr fonctionne avec des chaînes d'octets, donc cela prend
des pointeurs vides comme paramètre, plus un troisième caractère, représentant,
comme indiqué dans le man, la longueur supposée des deux chaînes.
Cela signifie que cela memcmp() ne comparera pas plus de   n    octets.


VALEUR RENVOYEE :
La valeur renvoyée dépend de la différence trouvée.

 Si les deux chaînes sont identiques, le résultat renvoyé sera le même, 0
 car il n'y a aucune différence. (s1 - s2)

 S'il y a une différence et que le premier caractère différent
 dans s2 est supérieur au caractère à la même place dans s1,
 le résultat renvoyé sera négatif. (s1 - s2)
 Si le contraire, le resultat sera positif


*/
