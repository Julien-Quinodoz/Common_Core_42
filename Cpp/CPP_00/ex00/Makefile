# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 18:13:39 by jquinodo          #+#    #+#              #
#    Updated: 2025/03/25 09:41:45 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
O=obj
OBJ=$(SRC:%.cpp=$O/%.o)

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m
RED 		=	\033[0;91m

all: $(NAME)

$O:
	@mkdir -p $@

$O/%.o: %.cpp | $O
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(BLUE)> $<$(END)\n"

$(NAME): $(OBJ) Makefile
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
	printf "$(YELLOW)$@ made$(END) ✅\n"

clean:
	rm -rdf $O
	printf "$(RED)$O removed$(END) 💥\n"

fclean: clean
	rm -f $(NAME)
	printf "$(RED)$(NAME) removed$(END) 💥\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT: