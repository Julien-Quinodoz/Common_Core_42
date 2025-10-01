/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:40:59 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:13 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (ptr);
}
/*
Explication compréhensible
la fonction fait la même chose que strchr,
 mais localise la dernière occurrence de c.

 explication strchr:
La fonction recherche un caractère dans une chaîne.
Si elle trouve le caractère, elle renvoie un pointeur vers la première
 occurrence de ce caractère spécifique.

S'il ne trouve aucune occurrence de ce caractère, il renvoie NULL.


retour :
Nous devons également renvoyer un pointeur vers le caractère
si le caractère est \0.


*/
