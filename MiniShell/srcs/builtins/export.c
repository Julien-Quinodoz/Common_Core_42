/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:51 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 21:01:06 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** Fonction qui affiche les erreurs liées à l'exportation d'une variable d'env.
** Elle affiche le message d'erreur approprié en fonction de l'argument.
 Affichage de l'argument invalide */

static int	print_error(int error, const char *arg)
{
	int	i;

	if (error == -1)
		ft_putstr_fd("export: not valid in this context: ", 2);
	else if (error == 0 || error == -3)
		ft_putstr_fd("export: not a valid identifier: ", 2);
	i = 0;
	while (arg[i] && (arg[i] != '=' || error == -3))
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return (1);
}

/*
 Fonction pour ajouter une nouvelle variable d'environnement à la liste 'env'.
 Si le noeud 'env' est vide, on lui assigne directement la valeur.
 Sinon, on alloue un nouveau noeud et on l'ajoute à la liste chaînée.
 Si l'environnement est vide, on assigne directement la valeur au noeud
 Crée et attribution de la valeur à un nouveau noeud
 Recherche du dernier noeud de la liste pour y ajouter le nouveau noeud
*/
int	env_add(const char *value, t_env *env)
{
	t_env	*new;

	if (env && env->value == NULL)
	{
		env->value = ft_strdup(value);
		return (0);
	}
	new = malloc(sizeof(t_env));
	if (!new)
		return (-1);
	new->value = ft_strdup(value);
	while (env && env->next)
		env = env->next;
	env->next = new;
	new->next = NULL;
	return (0);
}
/*
	Fonction pour extraire le nom de la variable d'environnement (avant '=')
 Elle copie le nom de la variable dans 'dest' jusqu'à '='.
*/

char	*get_env_name(char *dest, const char *src)
{
	int		i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '=' && i < BUFF_SIZE - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
 vérifie si une variable est déjà présente dans la liste d'environnements.
	Si elle est trouvée, la valeur de l'environnement est mise à jour .
 Extraction du nom de la variable à partir de l'argument 'args'
 Parcours de la liste d'environnements pour vérifier si la variable existe déjà
 Si la variable est trouvée, on met à jour sa valeur
*/

int	is_in_env(t_env *env, char *args)
{
	char	var_name[BUFF_SIZE];
	char	env_name[BUFF_SIZE];

	get_env_name(var_name, args);
	while (env)
	{
		get_env_name(env_name, env->value);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->value);
			env->value = ft_strdup(args);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

/*
	Fonction principale pour gérer l'exportation des variables d'environnement.
	Si l'argument est valide, elle ajoute la variable à l'environnement.
	Sinon, elle affiche les erreurs  ou la liste des variab existantes.
	Vérification de la validité de l'argument
	Si la est valide, on vérifie si elle existe dans l'environnement, si oui
	ont la met à jour
Si la variable n'existe pas, on l'ajoute a env + enc secret
*/
int	ft_export(char **args, t_env *env, t_env *secret)
{
	int		error_ret;
	int		new_env;

	new_env = 0;
	if (!args[1])
	{
		print_sorted_env(secret);
		return (0);
	}
	error_ret = is_valid_env(args[1]);
	if (args[1][0] == '=')
		error_ret = -3;
	if (error_ret <= 0)
		return (print_error(error_ret, args[1]));
	if (error_ret == 2)
		new_env = 1;
	else
		new_env = is_in_env(env, args[1]);
	if (new_env == 0)
	{
		if (error_ret == 1)
			env_add(args[1], env);
		env_add(args[1], secret);
	}
	return (0);
}
