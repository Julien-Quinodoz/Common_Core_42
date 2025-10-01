/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:48 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:18:40 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
Explication compréhensible

la fonction compare la chaîne dans un ordre lexicographique, ce qui signifie
qu'il compare chaque caractère par leurs valeurs ASCII correspondantes.
la fonction Compare le nombre maximal de  n  caractères dans les deux chaînes.

retour :
La valeur renvoyée dépend de la différence trouvée.
 Si les deux chaînes sont identiques, le résultat renvoyé sera le même, 0
 car il n'y a aucune différence. (s1 - s2)

 S'il y a une différence et que le premier caractère différent
 dans s2 est supérieur au caractère à la même place dans s1,
 le résultat renvoyé sera négatif. (s1 - s2)
 Si le contraire, le resultat sera positif


*/
