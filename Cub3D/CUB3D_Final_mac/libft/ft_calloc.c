/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:28:14 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/17 16:29:39 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*mem;
	unsigned int	total;
	unsigned int	i;

	total = nmemb * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	i = 0;
	while (total--)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
/*
Explication compréhensible

elle  fonctionne de la même manière que malloc() , mais la différence
est que avec calloc() tous les octets de mémoire sont définis par    0
 au lieu de rester en  charabia qui était là en mémoire avant
 que nous l'allouions.

*/
