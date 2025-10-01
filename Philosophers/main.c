/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:13:28 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:41 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_end_condition(t_args *args, int *i)
{
	pthread_mutex_lock(&args->sync_mutex);
	if (get_time_ms() - args->philos[*i].last_meal_beginning
		>= (unsigned long long)args->time2die
		|| args->total_finished == args->philo_count)
	{
		if (args->max_meals != -1 && args->total_finished == args->philo_count)
		{
			args->everybody_full = true;
			pthread_mutex_unlock(&args->philos[*i].l_fork);
			printf("Every philosopher has eaten %d times\n", args->max_meals);
		}
		else
		{
			args->death_occured = true;
			pthread_mutex_unlock(&args->philos[*i].l_fork);
			printf("%llu %d died\n",
				get_time_ms() - args->start_time, args->philos[*i].nbr);
		}
		pthread_mutex_unlock(&args->sync_mutex);
		return (true);
	}
	if (*i + 1 == args->philo_count)
		*i = -1;
	pthread_mutex_unlock(&args->sync_mutex);
	return (false);
}

int	main(int argc, char **argv)
{
	t_args		args;
	int			i;

	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6
		|| !initialize_args(&args, argv))
		return (1);
	initialize_philos(&args);
	i = -1;
	while (++i < args.philo_count)
		pthread_create(&args.philos[i].thread, NULL, routine, &args.philos[i]);
	i = -1;
	while (++i < args.philo_count && !check_end_condition(&args, &i))
		i = i + 0;
	i = -1;
	while (++i < args.philo_count)
		pthread_join(args.philos[i].thread, NULL);
	i = -1;
	while (++i < args.philo_count)
		pthread_mutex_destroy(&args.philos[i].l_fork);
	return (0);
}
