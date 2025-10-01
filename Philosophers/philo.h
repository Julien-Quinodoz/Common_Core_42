/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:12:58 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:49 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				nbr;
	uint64_t		last_meal_beginning;
	int				meals_count;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_args	*args;
}	t_philo;

typedef struct s_args
{
	int					philo_count;
	int					time2die;
	int					time2eat;
	int					time2sleep;
	int					max_meals;
	int					total_finished;
	bool				death_occured;
	bool				everybody_full;
	uint64_t			start_time;
	pthread_mutex_t		sync_mutex;
	struct s_philo		philos[200];
}	t_args;

enum e_fork
{
	LEFT,
	RIGHT
};

int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
bool		is_int(char *str);
uint64_t	get_time_ms(void);
size_t		ft_strlen(const char *str);
void		sleep_ms(uint64_t milli);
bool		initialize_args(t_args *args, char **argv);
void		initialize_philos(t_args *args);
bool		check_end_condition(t_args *args, int *i);
bool		write_status(t_philo *philo, char *msg);
bool		check_stop_condition(t_philo *philo);
bool		take_forks(t_philo *philo);
bool		sleep_and_think(t_philo *philo);
void		*routine(void	*data);

#endif