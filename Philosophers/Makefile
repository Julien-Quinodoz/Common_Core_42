# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 18:13:20 by jquinodo          #+#    #+#              #
#    Updated: 2025/01/27 11:06:43 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra -g

SRCS := main.c \
		init.c \
		philo_utils.c \
		utils/ft_atoi.c \
		utils/ft_calloc.c \
		utils/ft_isdigit.c \
		utils/is_int.c \
		utils/get_time_ms.c \
		utils/ft_strlen.c \
		utils/sleep_ms.c \

OBJS := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -I./

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -pthread

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
