/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:58:08 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/06 16:14:38 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[i] = malloc_word(s, c);
			if (!arr[i])
				return (free_split(arr, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
/*
Alloue (avec malloc) et renvoie un tableau de chaînes
obtenu en divisant 's' en utilisant le caractère 'c' comme délimiteur.$
(=> un tableau de tableaux, puisque les chaînes sont des tableaux de
 caractères terminés par un caractère NUL).

Nous pouvons également formuler cela sous forme de tableau de mots,
nous prenons la chaîne set nous la divisons pour obtenir un tableau
contenant chacun de ses mots. Chaque mot est séparé par un ou plusieurs c,
c'est notre délimiteur de mots.

il est également dit que notre tableau de mots doit être terminé par NUL.
Cela signifie que nous devons allouer un élément supplémentaire dans
 notre tableau, que nous pouvons définir à 0. En faisant cela, nous avons
  un moyen simple de faire une boucle sur notre tableau de mots, de la
  même manière que pour une chaîne : while(words[i] != 0).
*/
