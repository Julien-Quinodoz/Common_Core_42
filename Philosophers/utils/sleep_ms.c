/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:15:35 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:34 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_ms(uint64_t milli)
{
	uint64_t	now;
	uint64_t	elapsed;

	now = get_time_ms();
	elapsed = get_time_ms();
	while (elapsed - now < milli)
	{
		usleep(333);
		elapsed = get_time_ms();
	}
}
