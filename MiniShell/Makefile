# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 18:40:17 by jquinodo          #+#    #+#              #
#    Updated: 2025/04/18 22:12:28 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = clang

# Add Homebrew readline paths - adjust these to your Homebrew location
READLINE_PATH = $(shell brew --prefix readline 2>/dev/null || echo "/opt/homebrew")
READLINE_INC = -I$(READLINE_PATH)/include
READLINE_LIB = -L$(READLINE_PATH)/lib

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes/ $(READLINE_INC)

LIBFT = -L libft -lft

HEADER = minishell.h

BUILTINS = cd echo env exit export pwd unset

ENV = env get_env sort_env shlvl

EXEC_FILES = command_processor.c builtin_handler.c external_executor.c \
			 redirection.c pipe_handler.c signal_handler.c redirect_manager.c \
			 heredoc.c external_utils.c

MAIN = minishell main minishell_utils

PARSING = lexer lexer_utils lexer_utils2 parser parser_utils utils env_utils token_utils \
			token_create

TOOLS = fd free token type expansions expansions_utils   \
		parsing parsing_utils lets_go error_message dollar cap command_processor_utils \
		ft_itoa_buf

SRCS = $(addprefix srcs/builtins/, $(addsuffix .c, $(BUILTINS))) \
	  $(addprefix srcs/env/, $(addsuffix .c, $(ENV))) \
	  $(addprefix srcs/exec/, $(EXEC_FILES)) \
	  $(addprefix srcs/main/, $(addsuffix .c, $(MAIN))) \
	  $(addprefix srcs/parsing/, $(addsuffix .c, $(PARSING))) \
	  $(addprefix srcs/tools/, $(addsuffix .c, $(TOOLS)))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling minishell ... OK  ✅"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_LIB) -lreadline -lhistory
	@echo "\n"
	@tput clear  # Nettoie l'écran pour un effet plus dramatique
	@printf "\033[38;5;220m"  #
	@echo "╔══════════════════════════════════════════════════════════════════╗"
	@echo "║                                                                  ║"
	@echo "║                           MINISHELL                              ║"
	@echo "║                                                                  ║"
	@echo "║    jquinodo                                            rtari-ca  ║"
	@echo "║                                                                  ║"
	@echo "╚══════════════════════════════════════════════════════════════════╝"
	@printf "\033[1;21m\033[38;5;74m"
	@for letter in L E T "'" S " " G O "   ! "; do \
		printf "      %s" "$$letter"; \
		sleep 0.05; \
	done
	@echo "\n"
	@printf "\033[1;21m\033[38;5;220m"
	@for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 ; do \
		printf " * 🚀"; \
		sleep 0.05; \
	done
	@echo "\n\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@
	@tput el

clean:
	@make clean -C libft/
	@echo "\033[38;5;196m"
	@echo " Removing binaries..."
	@rm -f $(OBJS)
	@echo "\033[38;5;121m     ✅  OK !"
	@echo "\033[0m"

fclean: clean
	@make fclean -C libft/
	@echo "\033[38;5;196m  Deleting executable..."
	@rm -f $(NAME)
	@echo "\033[38;5;121m     ✅  OK !"
	@echo "\033[0m"

re: fclean all

test: all
	./minishell

norm:
	norminette $(SRCS) includes/$(HEADER)

.PHONY: clean fclean re test norm
