/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:54:23 by jquinodo          #+#    #+#             */
/*   Updated: 2025/01/13 11:09:52 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# include "../push_swap.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define CHECKER_H
# define BUFFER_SIZE 6

/*** Get next line Julien  ****/

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t Count, size_t Size);
size_t	ft_strlen(const char *str);
char	*ft_join(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_new_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

#endif
