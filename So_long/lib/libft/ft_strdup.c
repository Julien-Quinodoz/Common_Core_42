/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:37:35 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:52:06 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*s2;

	i = 0;
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*

DESCRIPTION
    La fonction strdup() alloue suffisamment de mémoire pour une copie
	de la chaîne s1,
	effectue la copie et renvoie un pointeur vers celle-ci.
	 Le pointeur peut ensuite être utilisé comme argument de la fonction free(3).

	Si la mémoire disponible est insuffisante,
	NULL est renvoyé
*/
