/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:34:07 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/02 12:34:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static char	*ft_strjoin5(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (free(s1), new);
}

static int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*extract_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock || !stock[0])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*trim_stock(char *stock)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (free(stock), NULL);
	i++;
	while (stock[i + j])
		j++;
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (free(stock), NULL);
	j = 0;
	while (stock[i])
		new[j++] = stock[i++];
	new[j] = '\0';
	return (free(stock), new);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock;
	char		buf[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	bytes = 1;
	while (bytes > 0 && !has_newline(stock))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stock), stock = NULL, -1);
		buf[bytes] = '\0';
		stock = ft_strjoin5(stock, buf);
		if (!stock)
			return (-1);
	}
	*line = extract_line(stock);
	if (!*line && (!stock || !stock[0]))
		return (free(stock), stock = NULL, 0);
	if (!*line)
		return (free(stock), stock = NULL, -1);
	stock = trim_stock(stock);
	return (1);
}
