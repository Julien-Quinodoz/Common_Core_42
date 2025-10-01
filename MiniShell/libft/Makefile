# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 19:02:10 by jquinodo          #+#    #+#              #
#    Updated: 2025/04/02 11:56:45 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FONCTIONS = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
	ft_strchr ft_strdup ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr \
	ft_strrchr ft_tolower ft_toupper ft_substr ft_strjoin ft_strtrim ft_split \
	ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd \
	ft_putnbr_fd ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
	ft_lstdelone ft_lstclear ft_lstiter ft_lstmap ft_ptf_putstr ft_ptf_putptr \
	ft_ptf_putnbr_hexa ft_ptf_putnbr ft_ptf_putchar ft_strcmp ft_memdel \
	ft_strisnum ft_printf ft_putendl ft_putstr ft_skip_spacenl ft_skip_space \
	get_next_line 

SRCS = $(addsuffix .c, $(FONCTIONS))

OBJ	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -rf

AR		= ar rcs

RANLIB		= ranlib

CFLAGS += -Wall -Werror -Wextra -g -Iincludes


all	:	$(NAME)

$(NAME)	: $(OBJ)
	@echo "\033[0;32m\n Compiling libft     ... OK  ✅ "
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)

%.o: %.c
	@printf "\033[0;33m Generating libft objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@tput el

clean	:
		@echo "\033[38;5;196m\n Cleaning libft..."
		@$(RM) $(OBJ)
		@echo "\033[0m"
		@echo "\033[38;5;121m     ✅  OK !"

fclean	:	clean
		@echo "\n \033[38;5;196m Deleting executable libft ...\n"
		@$(RM) $(NAME)
		@echo "\n\033[38;5;121m     ✅  OK !"

re	:	fclean all

.PHONY:		all clean fclean re
