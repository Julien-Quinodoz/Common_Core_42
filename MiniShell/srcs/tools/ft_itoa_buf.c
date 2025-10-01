/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:11:25 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/16 23:15:18 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Helper function to convert an integer to a string in a buffer.
 * Returns the length of the result string. */
static int	get_int_length(int n)
{
	int	len;
	int	temp;

	len = 1;
	temp = n;
	while (1)
	{
		temp = temp / 10;
		if (temp == 0)
			break ;
		len++;
	}
	return (len);
}

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void	fill_number(char *buf, int n, int i, int neg)
{
	int	digit;

	while (n)
	{
		digit = n % 10;
		if (neg)
			digit *= -1;
		i--;
		buf[i] = digit + '0';
		n /= 10;
	}
}

int	ft_itoa_buf(int n, char *buf)
{
	int	len;
	int	neg;
	int	i;

	neg = is_negative(n);
	len = get_int_length(n);
	i = len;
	if (neg)
		i++;
	buf[i] = '\0';
	if (neg)
		buf[0] = '-';
	if (n == 0)
		buf[0] = '0';
	fill_number(buf, n, i, neg);
	if (neg)
		return (len + 1);
	return (len);
}
