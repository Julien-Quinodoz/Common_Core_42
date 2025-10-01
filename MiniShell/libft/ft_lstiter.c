/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:11:31 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/16 15:14:57 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
Paramètres
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.

Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu chaque élément.

*/
