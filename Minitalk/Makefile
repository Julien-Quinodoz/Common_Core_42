# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:29:56 by jquinodo          #+#    #+#              #
#    Updated: 2024/11/23 13:18:27 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
LIBFT_DIRECTORY = libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a
CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIRECTORY) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_DIRECTORY) -lft

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_DIRECTORY)

clean:
	$(MAKE) -C $(LIBFT_DIRECTORY) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIRECTORY) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
