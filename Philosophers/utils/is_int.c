/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:14:15 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:29 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_int(char *str)
{
	char	*max_int;
	size_t	str_len;

	max_int = "2147483647";
	if (*str == '+')
		str++;
	str_len = ft_strlen(str);
	if (str_len > 10)
		return (false);
	if (str_len == 10)
		while (ft_isdigit(*str) && *str <= *max_int++)
			str++;
	else
		while (ft_isdigit(*str))
			str++;
	return (!*str && true);
}
