/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:38:28 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 16:05:13 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
la fonction copie une chaîne dans une autre,
mais elle termine toujours
par NUL

Si  dstsize est suffisament long pour terminer la chaîne par NUL sans
la tronquer, la fonction copiera simplement la chaîne, comme vous le
feriez avec strcpy().
Si vous ne donnez pas un dstsize suffisament long,
 cela copiera        dstsize - 1
les caractères de la source vers la destination, en ajoutant ensuite le
caractère de terminaison NUL.

retour:
la fonction renvoie toujours la longueur de la chaîne qu'elle a essayé de créer,
c'est la longueur de src, même si vous devez tronquer la chaîne pour
la terminer par NUL.
*/
