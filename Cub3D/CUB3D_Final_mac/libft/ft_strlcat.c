/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:39:50 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 15:45:34 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*s;
	size_t	len_dst;
	size_t	ret;
	size_t	len_src;
	size_t	i;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	ret = 0;
	i = 0;
	if (dst_size > len_dst)
		ret = len_src + len_dst;
	else
		ret = len_src + dst_size;
	while (s[i] && (len_dst + 1) < dst_size)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (ret);
}
/*
Explication compréhensible

la fonction est conçue pour concaténer deux chaînes mais , elle terminera
toujours la chaîne par NUL.

Si dstsize est suffisament long pour terminer par NUL;  la chaîne concaténée
résultante sans la tronquer, la fonction concatènera simplement les deux chaînes,
comme strcat
Si dst_size est trop petit , il concatènera les caractères, en ajoutant le
caractère de terminaison NUL après cela :        dst_size - strlen(dst) - 1

retour :
la fonction renvoie toujours la longueur de la chaîne qu'elle a essayé de créer,
c'est-à-dire la longueur d'origine de dst plus la longueur d'origine de src,
même si vous devez tronquer la chaîne pour la terminer par NUL.

*/
