/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:56 by jquinodo          #+#    #+#             */
/*   Updated: 2025/02/24 18:58:02 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
1  Fonction qui affiche le répertoire de travail actuel.
2 Elle utilise la fonction getcwd pour récupérer le répertoire de travail actuel.
3 Si une erreur lors de la récupération du répertoire, un message d'erreur
   est affiché et la fonction ret 1. Sinon, elle affiche le chemin et retourne 0.
*/
int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("minishell: pwd");
		return (1);
	}
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (0);
}
