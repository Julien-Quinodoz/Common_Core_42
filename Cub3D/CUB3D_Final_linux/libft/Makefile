# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 19:02:10 by jquinodo          #+#    #+#              #
#    Updated: 2024/11/23 11:16:00 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_ptf_putstr.c \
		ft_ptf_putptr.c \
		ft_ptf_putnbr_hexa.c \
		ft_ptf_putnbr.c \
		ft_ptf_putchar.c \
		ft_printf.c

NAME	=	libft.a

OBJ	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -rf

AR		= ar rcs

RANLIB		= ranlib

CFLAGS += -Wall -Werror -Wextra -g

LFLAGS += -I.

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY:		all clean fclean re
