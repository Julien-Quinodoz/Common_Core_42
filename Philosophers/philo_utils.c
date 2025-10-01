/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:37:15 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:47 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_stop_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->sync_mutex);
	if (philo->args->death_occured || philo->args->everybody_full)
	{
		pthread_mutex_unlock(&philo->args->sync_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->args->sync_mutex);
	return (false);
}

bool	write_status(t_philo *philo, char *msg)
{
	if (check_stop_condition(philo))
		return (false);
	pthread_mutex_lock(&philo->args->sync_mutex);
	printf("%llu %d %s\n", get_time_ms() - philo->args->start_time,
		philo->nbr, msg);
	pthread_mutex_unlock(&philo->args->sync_mutex);
	return (true);
}

bool	take_forks(t_philo *philo)
{
	if (check_stop_condition(philo))
		return (false);
	pthread_mutex_lock(&philo->l_fork);
	if (!write_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->l_fork);
		return (false);
	}
	if (check_stop_condition(philo))
		return (false);
	pthread_mutex_lock(philo->r_fork);
	if (!write_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (false);
	}
	return (true);
}

bool	sleep_and_think(t_philo *philo)
{
	if (!write_status(philo, "is sleeping"))
		return (false);
	sleep_ms(philo->args->time2sleep);
	if (!write_status(philo, "is thinking"))
		return (false);
	return (true);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!(philo->nbr & 1))
		sleep_ms(10);
	while (1)
	{
		if (!take_forks(philo))
			break ;
		pthread_mutex_lock(&philo->args->sync_mutex);
		philo->meals_count++;
		philo->last_meal_beginning = get_time_ms();
		pthread_mutex_unlock(&philo->args->sync_mutex);
		write_status(philo, "is eating");
		sleep_ms(philo->args->time2eat);
		pthread_mutex_lock(&philo->args->sync_mutex);
		if (philo->meals_count == philo->args->max_meals)
			philo->args->total_finished += (philo->args->max_meals != -1);
		pthread_mutex_unlock(&philo->args->sync_mutex);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (!sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
