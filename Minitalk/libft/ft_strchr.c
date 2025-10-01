/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:40:38 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:51:37 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	i = 0;
	ch = (char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && ch == '\0')
		return (str + i);
	return (NULL);
}
/*
Explication compréhensible
La fonction recherche un caractère dans une chaîne.
Si elle trouve le caractère, elle renvoie un pointeur vers la première
 occurrence de ce caractère spécifique.

S'il ne trouve aucune occurrence de ce caractère, il renvoie NULL.


retour :
Nous devons également renvoyer un pointeur vers le caractère
si le caractère est \0.

*/
