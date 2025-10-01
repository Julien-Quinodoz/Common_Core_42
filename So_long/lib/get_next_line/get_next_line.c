/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:09:30 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/06 10:32:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		new_line[i++] = '\n';
	return (new_line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer_tmp;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer_tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer_tmp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer_tmp);
			free(res);
			return (NULL);
		}
		buffer_tmp[byte_read] = 0;
		res = ft_join(res, buffer_tmp);
		if (ft_strchr(buffer_tmp, '\n'))
			break ;
	}
	free(buffer_tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_new_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1;
	char *line1;
	int i;

	i = 1;
	fd1 = open("t3.txt", O_RDONLY);

	while(i < 10)
	{
		line1 = get_next_line(fd1);
		printf("\n");
		printf("line %d ---> \n %s \n", i , line1);
		printf("††††††††††††††††††††††††††††††††\n");
		i++;
	}
	free(line1);
	return (0);
}
*/
