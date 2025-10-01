/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:18:49 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/04 17:55:58 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Fonction qui retourne la taille d'un node (nom de la variable) jusqu'='.*/
/* On parcourt la chaîne jusqu'à trouver '=' ou atteindre la fin de la chaîne */
static size_t	node_size(char *node)
{
	size_t	i;

	i = 0;
	while (node[i] && node[i] != '=')
		i++;
	return (i);
}

static void	free_node(t_mini *mini, t_env *node)
{
	if (!node)
		return ;
	ft_memdel(node->value);
	ft_memdel(node);
	if (mini->env == node)
		mini->env = NULL;
}
/*
Fonction qui gère la suppression du premier noeud de la liste d'environnements.
Si le premier noeud correspond à la variable à supprimer,
 on met à jour la tête de la liste.
 Si le premier noeud correspond à l'élément à supprimer
 On met à jour la tête de la liste si le noeud a un suivant
 On libère la mémoire du noeud supprimé */

static int	unset_first_node(char **a, t_mini *mini)
{
	t_env	*cur_node;

	if (!mini->env)
		return (0);
	cur_node = mini->env;
	if (ft_strncmp(a[1], cur_node->value, node_size(cur_node->value)) == 0)
	{
		if (cur_node->next)
			mini->env = cur_node->next;
		free_node(mini, cur_node);
		return (1);
	}
	return (0);
}
/*
 Fonction qui supprime un élément de la liste d'environnements.
	 Elle cherche l'élément spécifié par son nom et le supprime de la liste.
	 On tente de supprimer le premier noeud
	 Parcours de la liste pour trouver et supprimer le noeud correspondant
 On met à jour les liens pour retirer le noeud de la liste */

int	ft_unset(char **a, t_mini *mini)
{
	t_env	*current_node;
	t_env	*next_node;

	if (!a[1] || !mini->env)
		return (0);
	if (unset_first_node(a, mini))
		return (0);
	current_node = mini->env;
	while (current_node && current_node->next)
	{
		if (ft_strncmp(a[1], current_node->next->value,
				node_size(current_node->next->value)) == 0)
		{
			next_node = current_node->next->next;
			free_node(mini, current_node->next);
			current_node->next = next_node;
			return (0);
		}
		current_node = current_node->next;
	}
	return (0);
}
