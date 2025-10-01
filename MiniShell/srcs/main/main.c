/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:20:57 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/18 20:59:55 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_mini(t_mini *mini, char **env)
{
	display_lets_go();
	mini->in = dup(STDIN);
	mini->out = dup(STDOUT);
	mini->exit = 0;
	mini->ret = 0;
	mini->no_exec = 0;
	reset_fds(mini);
	env_init(mini, env);
	secret_env_init(mini, env);
	increment_shell_level(mini->env);
}

static void	run_shell_loop(t_mini *mini)
{
	while (mini->exit == 0)
	{
		initialize_signals();
		custom_parse(mini);
		if (mini->start != NULL)
		{
			if (check_line(mini, mini->start))
				minishell(mini);
		}
		free_token_and_null(&mini->start);
	}
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void)ac;
	(void)av;
	init_mini(&mini, env);
	run_shell_loop(&mini);
	free_env(mini.env);
	free_env(mini.secret_env);
	return (mini.ret);
}
