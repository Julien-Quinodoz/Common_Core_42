/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:14:25 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/15 16:48:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = s2[i];
	return (res);
}
/*
Cette fonction fonctionne exactement  de la même manière que
ft_strlcat  (concaténer deux chaînes mais , elle terminera
toujours la chaîne par NUL)
mais au lieu de lui passer un destination string qui doit être correctement
alloué en tant que paramètre, nous ne passons que deux strings et ft_strjoin
allouerons la mémoire requise pour les deux plus le caractère de terminaison NUL.

s1 sera la première chaîne dans le résultat, s2la seconde.

Nous devons obtenir la longueur des deux chaînes afin de pouvoir
allouer suffisamment de mémoire pour les deux.

puis allouer suffisamment de mémoire pour la chaîne et le caractère de
terminaison NUL.

Nous copions ensuite s1dans notre chaîne nouvellement allouée, puis nous copions
s2, et enfin nous pouvons définir le dernier caractère comme NUL.

}*/
