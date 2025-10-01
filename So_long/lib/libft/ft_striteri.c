/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:56:12 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 10:45:04 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
Description
Applique la fonction f à chaque caractère de la chaine de caractères
passée en paramètre en précisant son index en pre- mier argument.
Chaque caractère est passé par adresse à la fonction f afin de
pouvoir être modifié si nécéssaire.
Param. #1
La chaine de caractères sur laquelle itérer.
Param. #2
 La fonction à appeler sur chaque caractère de s et son index.

 Retour
 Rien.
*/
