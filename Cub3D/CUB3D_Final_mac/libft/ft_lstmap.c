/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:34:14 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/17 12:28:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	new_lst = NULL;
	while (lst)
	{
		elem = malloc(sizeof(t_list));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		elem -> content = f(lst ->content);
		elem -> next = NULL;
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
/*
Cette fonction fonctionne de manière similaire à la fonction ft_lstiter ,
 mais elle crée une nouvelle liste résultant des applications successives de f
  sur le contenu de chaque élément.
*/
