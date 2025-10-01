/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:19:23 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/09 14:59:36 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	sort_env(char **tab, int env_len)
{
	int		ordered;
	int		i;
	char	*tmp;

	if (!tab || env_len <= 1)
		return ;
	ordered = 0;
	while (env_len > 1 && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		env_len--;
	}
}

void	print_sorted_env(t_env *env)
{
	int		i;
	char	**tab;
	char	*str_env;

	str_env = env_to_str(env);
	if (!str_env)
		return ;
	tab = ft_split(str_env, '\n');
	ft_memdel(str_env);
	if (!tab)
		return ;
	sort_env(tab, str_env_len(tab));
	i = 0;
	while (tab[i])
	{
		ft_putstr("declare -x ");
		ft_putendl(tab[i]);
		i++;
	}
	free_tab(tab);
}
