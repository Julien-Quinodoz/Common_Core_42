/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:06:26 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/23 10:11:21 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptf_putstr(char *str1)
{
	int	len;

	if (!str1)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str1 != '\0')
	{
		if (write(1, str1, 1) == -1)
			return (-1);
		len++;
		str1++;
	}
	return (len);
}
