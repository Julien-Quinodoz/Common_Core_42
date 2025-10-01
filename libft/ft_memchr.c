/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:09 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 16:17:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
La fonction fonctionne de manière similaire à la strchr(),
 la différence est qu'elle fonctionne avec une chaîne d'octets ( void *)
 alors qu'elle strchr()fonctionne avec des chaînes « littérales » ( char *).

Cela signifie que nous pouvons envoyer n'importe quel type de données
que nous voulons memchr()et cela fonctionnera toujours.

la fonction a également un troisième paramètre, n.
Ce paramètre indique à la fonction dans combien d'octets nous voulons effectuer
la recherche.
 Nous avons besoin de ce paramètre car sce n'est pas une chaîne « littérale »,
 elle n'a pas de caractère de terminaison NUL.
 Si nous n'avions pas ce paramètre, nous aurions lu un nombre aléatoire d'octets.
*/
