/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:57:47 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:55:18 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ischar(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
		if (*(set + i++) == c)
			return (1);
	return (0);
}

static char	*trimming(const char *s1, const char *set, size_t *k, size_t i)
{
	size_t	j;
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	j = 0;
	while (ischar(*(s1 + len - j - 1), set))
		j++;
	dst = ft_calloc(sizeof(char), len - (j + i) + 1);
	if (dst == NULL)
		return (NULL);
	while (*k < len - (j + i))
	{
		*(dst + *k) = *(s1 + i + *k);
		*k += 1;
	}
	return (dst);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ischar(*(s1 + i), set))
		i++;
	k = 0;
	if (i == len)
		dst = malloc(1);
	else
		dst = trimming(s1, set, &k, i);
	if (dst != NULL)
		*(dst + k) = '\0';
	return (dst);
}
/*
 DESCRIPTION :
 La fonction prend une chaîne et la coupe debut et fin par set

Le rognage (trim) signifie supprimer les caractères spécifiés dans
 la chaîne (SET) du début ET de la fin de la chaîne s1, sans supprimer
 les caractères qui se trouvent au milieu de la chaîne s1.
 exemple :
            ababaaaMy name is Julienbbaaabbad   SET = ab
resultat : My name is Julien

boucler sur la chaîne; avancer pendant que nous avons un caractère à supprimer.
puis la même chose à partir de la fin de la chaîne, ce qui nous laisse
avec un index de début et de fin pour notre chaîne coupée.

*/
