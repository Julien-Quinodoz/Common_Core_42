/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:41 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/09 17:16:40 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Fonction qui gère l'affichage des erreurs pour la commande cd */
/* Si trop d'arguments ont été fournis, affiche un message d'erreur */
/* Sinon, affiche l'erreur avec la description  liée au code errno. */
/* Affiche le chemin qui a posé problème */
/* Fonction qui récupère la valeur d'une variable d'environnement donnée */
static void	print_error(char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(args[1], 2);
}

/* Fonction qui récupère la valeur d'une variable d'environnement donnée */
/* Si la variable d'env. correspond  (comparaison sur la longueur) */
/* On copie la partie de la chaîne après le nom (après =) de la variable */
/* Retourne NULL si la variable d'environnement n'est pas trouvée */
static char	*get_env_path(t_env *env, const char *var, size_t len)
{
	char	*oldpwd;
	int		i;
	int		j;
	int		s_alloc;

	while (env && env->next)
	{
		if (!ft_strncmp(env->value, var, len))
		{
			s_alloc = ft_strlen(env->value) - len;
			oldpwd = malloc(sizeof(char) * s_alloc + 1);
			if (!oldpwd)
				return (NULL);
			i = 0;
			j = 0;
			while (env->value[i++])
				if (i > (int)len)
					oldpwd[j++] = env->value[i];
			oldpwd[j] = '\0';
			return (oldpwd);
		}
		env = env->next;
	}
	return (NULL);
}

/*  Met à jour la variable d'environnement OLDPWD avec le répertoire courant
	1. Récupère le répertoire courant dans 'cwd'.
	2. Crée la chaîne "OLDPWD=<répertoire courant>".
	3. Met à jour OLDPWD dans l'environnement ou l'ajoute si elle n'existe
	4. Libère la mémoire allouée et retourne 0 en cas de succès, 1 sinon */
static int	update_oldpwd(t_env *env)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (ERROR);
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	if (!oldpwd)
		return (ERROR);
	if (is_in_env(env, oldpwd) == 0)
		env_add(oldpwd, env);
	ft_memdel(oldpwd);
	return (SUCCESS);
}

/* Fonction principale de la commande cd, qui gère les différentes options */
/* Si aucun argument, se rendre dans le répertoire HOME */
/* Sinon si l'argument est "-", se rendre dans le répertoire OLDPWD */
/* Sinon, tenter de se rendre dans le répertoire spécifié(env) */
/* Affiche l'erreur si la commande échoue & Ret le code d'erreur */
static int	go_to_path(int option, t_env *env)
{
	int		ret;
	char	*env_path;

	env_path = NULL;
	if (option == 0)
	{
		update_oldpwd(env);
		env_path = get_env_path(env, "HOME", 4);
		if (!env_path)
			ft_putendl_fd("minishell : cd: HOME not set", STDERR);
		if (!env_path)
			return (ERROR);
	}
	else if (option == 1)
	{
		env_path = get_env_path(env, "OLDPWD", 6);
		if (!env_path)
			ft_putendl_fd("minishell : cd: OLDPWD not set", STDERR);
		if (!env_path)
			return (ERROR);
		update_oldpwd(env);
	}
	ret = chdir(env_path);
	ft_memdel(env_path);
	return (ret);
}

/* Fonction principale de la commande cd, qui gère les différentes options */
/* Si aucun argument, se rendre dans le répertoire HOME */
/* Sinon si l'argument est "-", se rendre dans le répertoire OLDPWD */
/* Sinon, tenter de se rendre dans le répertoire spécifié(env) */
/* Affiche l'erreur si la commande échoue & Retourne le code d'erreur */
int	ft_cd(char **args, t_env *env)
{
	int		cd_ret;

	if (!args[1])
		return (go_to_path(0, env));
	if (ft_strcmp(args[1], "-") == 0)
		cd_ret = go_to_path(1, env);
	else
	{
		update_oldpwd(env);
		cd_ret = chdir(args[1]);
		if (cd_ret < 0)
			cd_ret *= -1;
		if (cd_ret != 0)
			print_error(args);
	}
	return (cd_ret);
}
