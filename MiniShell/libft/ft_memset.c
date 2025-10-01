/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:36:19 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 13:55:10 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_str;

	tmp_str = b;
	while (len > 0)
	{
		*tmp_str = (unsigned char)c;
		tmp_str++;
		len--;
	}
	return (b);
}

/*


Descrition:
La fonction memset() remplit les n premiers octets de la zone
*mémoire pointée par b avec l'octet .. c.
*//*
VALEUR RENVOYEE : La fonction memset( renvoie un pointeur sur la zone
mémoire b.
*/
/*
déclare un caractère temporaire non signé
déclare un caractère temporaire non signé
*/
/* boucle sur la variable temporaire alors qu'on n'a pas atteint len dans
cette boucle, définit l'octet actuel égal à c converti en caractère non signé
*/
/*
retour du premier paramètre de la fonction vide *b *
*/
