/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:36:57 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/17 14:07:17 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	str = s;
	i = 0;
	while (n--)
		str[i++] = 0;
}
/*
Explication compréhensible

Cette fonction fonctionne de la même manière que la
memset(), sauf que vous n'avez pas besoin de spécifier quel
caractère écrire, ce sera toujours 0( NUL caractère).

Cette fonction ne renvoie rien et si le nombre de caractères
à écrire que vous avez passé tel size_t n est 0, b zero ne fait rien.

#include <stdio.h>

void    ft_bzero(void *s, size_t n);

int main(void)
{
    char    str1[] = "";
    char    str2[] = "goodbye";

    ft_bzero(str1, 0);
    ft_bzero(str2, 1);

    printf("%s\n", str1);
    printf("%s\n",str2);
    return (0);
}
*/
