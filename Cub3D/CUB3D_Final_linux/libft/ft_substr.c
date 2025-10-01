/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:30:12 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:53:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
/*
la fonction renvoie une sous-chaîne tronquee de la chaîne spassée en paramètre.

Nous devons d’abord vérifier si l’ startindex est supérieur à la longueur
de la chaîne ou non.

Nous devons également vérifier si le startplus le lenest supérieur à la longueur
de la chaîne entière.

Ensuite, nous allouons suffisamment de mémoire pour la sous-chaîne et
copions s[start]  jusqu'à ce que nous atteignions len  les caractères copiés
dans notre nouvelle chaîne.

Et enfin, nous pouvons renvoyer la sous-chaîne.
*/
