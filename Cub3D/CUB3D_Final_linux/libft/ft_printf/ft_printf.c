/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:51:27 by jquinodo          #+#    #+#             */
/*   Updated: 2024/10/24 12:43:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	chek_format(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		check;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = chek_format(*(++str), args);
			if (check == -1)
				return (-1);
			i += check;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
