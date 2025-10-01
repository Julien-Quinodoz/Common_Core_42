# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 12:54:59 by jquinodo          #+#    #+#              #
#    Updated: 2025/07/03 12:55:07 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bureaucrat
O		=	obj
I		=	inc
S		=	src
SRC		=	$S/Bureaucrat.cpp \
			$S/AForm.cpp \
			$S/PresidentialPardonForm.cpp \
			$S/RobotomyRequestForm.cpp \
			$S/ShrubberyCreationForm.cpp \
			$S/main.cpp
INCS	=	$I/Bureaucrat.hpp \
			$I/AForm.hpp \
			$I/PresidentialPardonForm.hpp \
			$I/RobotomyRequestForm.hpp \
			$I/ShrubberyCreationForm.hpp
OBJ		=	$(SRC:$S/%.cpp=$O/%.o)
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I$I -g
LDFLAGS	=

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

all: $(NAME)

$O:
	@mkdir -p $O

$O/%.o: $S/%.cpp Makefile $(INCS) | $O
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(BLUE)-> $<$(END)\n"

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
	printf "$(GREEN)$(NAME) made$(END)\n"

clean:
	rm -rdf $O
	printf "$(YELLOW)$O removed$(END)\n"

fclean:	clean
	rm -f $(NAME)
	printf "$(YELLOW)$(NAME) removed$(END)\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
