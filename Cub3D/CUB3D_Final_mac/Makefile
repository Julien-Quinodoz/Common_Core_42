# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 19:20:52 by jquinodo          #+#    #+#              #
#    Updated: 2025/06/19 13:59:41 by jquinodo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables de compilation
CC = gcc
CFLAGS =  -g -Wall -Wextra -Werror
NAME = cub3D

# Répertoires
INC = inc
SRC = src
LIBFT_DIR = ./libft
MLX42_DIR = ./MLX42
MAP_UTILS = map_utils

# Fichiers d'en-tête
INCLUDES = $(INC)/cub3d.h
INC_MLX = $(MLX42_DIR)/include

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

# OS detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    # macOS
    FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
    GL_LIBS = -lglfw
    # macOS GLFW detection
    GLFW_PREFIX = $(shell brew --prefix glfw 2>/dev/null || echo "/usr/local")
    GLFW_EXISTS = $(shell test -d "$(GLFW_PREFIX)/lib" && echo "yes" || echo "no")
    ifeq ($(GLFW_EXISTS), yes)
        GLFW_PATH = -L"$(GLFW_PREFIX)/lib"
    else
        GLFW_PATH = -L"/opt/homebrew/lib" -L"/usr/local/lib"
    endif
else
    # Linux
    FRAMEWORKS =
    GL_LIBS = -lglfw -lGL -lm -ldl -lpthread
    # Linux GLFW detection
    GLFW_EXISTS = $(shell pkg-config --exists glfw3 && echo "yes" || echo "no")
    GLFW_PATH = $(shell pkg-config --libs-only-L glfw3 2>/dev/null || echo "-L/usr/local/lib")
endif

# Flags de linkage complets
LDFLAGS = $(FRAMEWORKS) $(GL_LIBS) $(GLFW_PATH)

# Sources mandataires
SRCS =	$(SRC)/cub3d.c \
		$(SRC)/draw_sprite.c \
		$(SRC)/rays.c \
		$(SRC)/window.c \
		$(SRC)/render.c \
		$(SRC)/draw1.c \
		$(SRC)/draw2.c \
		$(SRC)/keys_handler_1.c \
		$(SRC)/keys_handler_2.c \
		$(SRC)/keys_handler_3.c \
		$(SRC)/keys_handler_4.c \
		$(SRC)/draw_wall.c \
		$(SRC)/utils1.c \
		$(SRC)/utils2.c \
		$(SRC)/init.c \
		$(SRC)/play.c \
		$(MAP_UTILS)/main_parser.c \
		$(MAP_UTILS)/config_parser.c \
		$(MAP_UTILS)/texture_parser.c \
		$(MAP_UTILS)/color_parser.c \
		$(MAP_UTILS)/file_reader.c \
		$(MAP_UTILS)/map_reader.c \
		$(MAP_UTILS)/map_validator.c \
		$(MAP_UTILS)/map_processor.c \
		$(MAP_UTILS)/memory.c \
		$(MAP_UTILS)/validation.c \
		$(MAP_UTILS)/string_utils.c \
		$(MAP_UTILS)/get_next_line.c \
		$(MAP_UTILS)/get_next_line_utils.c

# Objets
OBJS = $(SRCS:.c=.o)

# Couleurs pour l'affichage
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
ORANGE = \033[0;38;5;214m
NC = \033[0m # No Color

# Fichier tampon pour check_glfw
CHECK_GLFW_STAMP := .glfw_checked

# Règles principales
all: $(CHECK_GLFW_STAMP) $(NAME)

$(NAME): $(LIBFT) $(MLX42_LIB) $(OBJS) $(INCLUDES)
	@echo "$(GREEN)Compilation de $(NAME)...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX42_LIB) $(LIBFT) $(LDFLAGS)
	@echo "$(GREEN)$(NAME) compilé avec succès!$(NC)"
	@$(MAKE) ascii_art

%.o: %.c $(INCLUDES)
	@printf "\rCompilation de $< ...         "
	@$(CC) $(CFLAGS) -I$(INC) -I$(INC_MLX) -I$(LIBFT_DIR) -c $< -o $@
	@printf "\r\033[K"  # Efface la ligne

# Compilation de libft
$(LIBFT):
	@echo "$(GREEN)Compilation de libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

# Compilation de MLX42
$(MLX42_LIB):
	@echo "$(GREEN)Compilation de MLX42...$(NC)"
	@if [ ! -d "$(MLX42_DIR)/build" ]; then \
		mkdir -p $(MLX42_DIR)/build; \
		cmake $(MLX42_DIR) -B $(MLX42_DIR)/build -DCMAKE_BUILD_TYPE=Release; \
	fi
	@$(MAKE) -C $(MLX42_DIR)/build -j4

# Force rebuild of libraries if they don't exist
.PHONY: check_libs
check_libs:
	@if [ ! -f "$(LIBFT)" ]; then \
		echo "$(YELLOW)libft.a missing, rebuilding...$(NC)"; \
		$(MAKE) $(LIBFT); \
	fi
	@if [ ! -f "$(MLX42_LIB)" ]; then \
		echo "$(YELLOW)libmlx42.a missing, rebuilding...$(NC)"; \
		$(MAKE) $(MLX42_LIB); \
	fi

# Vérification GLFW (exécutée une seule fois)
$(CHECK_GLFW_STAMP):
	@echo "Vérification de GLFW..."
ifeq ($(UNAME_S),Darwin)
	@if ! brew list glfw >/dev/null 2>&1; then \
		echo "$(RED)GLFW non trouvé. Installation en cours...$(NC)"; \
		brew install glfw; \
	else \
		echo "$(GREEN)GLFW détecté$(NC)"; \
	fi
else
	@if ! pkg-config --exists glfw3; then \
		echo "$(RED)GLFW non trouvé. Installation en cours...$(NC)"; \
		sudo apt-get update && sudo apt-get install -y libglfw3-dev; \
	else \
		echo "$(GREEN)GLFW détecté$(NC)"; \
	fi
endif
	@touch $(CHECK_GLFW_STAMP)

# Installation des dépendances
install_deps:
	@echo "$(YELLOW)Installation des dépendances...$(NC)"
ifeq ($(UNAME_S),Darwin)
	@if ! command -v brew >/dev/null 2>&1; then \
		echo "$(RED)Homebrew n'est pas installé. Veuillez l'installer d'abord.$(NC)"; \
		echo "$(YELLOW)Visitez: https://brew.sh$(NC)"; \
		exit 1; \
	fi
	@brew install glfw cmake
else
	@echo "$(YELLOW)Installation des dépendances Linux...$(NC)"
	@sudo apt-get update && sudo apt-get install -y \
		libglfw3-dev \
		cmake \
		gcc \
		make
endif
	@echo "$(GREEN)Dépendances installées avec succès!$(NC)"

# Nettoyage
clean:
	@echo "$(RED)Nettoyage des fichiers objets...✔️$(NC)"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Nettoyage complet...✔️$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_DIR)/build
	@rm -f $(CHECK_GLFW_STAMP)

# Recompilation complète
re: fclean check_libs all

# Règles de débogage
debug: CFLAGS += -DDEBUG -fsanitize=address
debug: re

# Affichage des informations système
info:
	@echo "$(YELLOW)Informations système:$(NC)"
	@echo "Compilateur: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "Architecture: $(shell uname -m)"
	@echo "GLFW Path: $(GLFW_PREFIX)"
	@echo "GLFW disponible: $(GLFW_EXISTS)"

# Test de compilation sans exécution
test_compile: $(LIBFT) $(MLX42_LIB) $(OBJS)
	@echo "$(GREEN)Test de compilation réussi!$(NC)"

# Aide
help:
	@echo "$(YELLOW)Makefile Cub3D - Commandes disponibles:$(NC)"
	@echo "  all          - Compile le projet principal"
	@echo "  clean        - Supprime les fichiers objets"
	@echo "  fclean       - Nettoyage complet"
	@echo "  re           - Recompilation complète"
	@echo "  debug        - Compilation avec débogage"
	@echo "  install_deps - Installe les dépendances"
	@echo "  info         - Affiche les informations système"
	@echo "  test_compile - Test de compilation"
	@echo "  help         - Affiche cette aide"

# Déclaration des règles non-fichiers
.PHONY: all clean fclean re debug info test_compile help install_deps check_libs

# ASCII Art avec dégradé de couleurs
ascii_art:
	@clear
	@bash -c '\
	text="CUB3D"; \
	len=$${#text}; \
	i=0; \
	while [ $$i -lt $$len ]; do \
		printf "\033[38;5;82m%s\033[0m " "$${text:$$i:1}"; \
		sleep 0.05; \
		i=$$((i+1)); \
	done; \
	printf "\n"; \
	'
	@printf "\033[38;5;82m                                      bbbbbbbb                                           dddddddd \n"
	@printf "\033[38;5;118m        CCCCCCCCCCCCC                 b::::::b             333333333333333               d::::::d \n"
	@printf "\033[38;5;154m     CCC::::::::::::C                 b::::::b            3:::::::::::::::33             d::::::d \n"
	@printf "\033[38;5;190m   CC:::::::::::::::C                 b::::::b            3::::::33333::::::3            d::::::d \n"
	@printf "\033[38;5;226m  C:::::CCCCCCCC::::C                  b:::::b            3333333     3:::::3            d::::::d  \n"
	@printf "\033[38;5;220m C:::::C       CCCCCCuuuuuu    uuuuuu  b:::::bbbbbbbbb                3:::::3    ddddddddd:::::d  \n"
	@printf "\033[38;5;214mC:::::C              u::::u    u::::u  b::::::::::::::bb              3:::::3  dd::::::::::::::d  \n"
	@printf "\033[38;5;208mC:::::C              u::::u    u::::u  b::::::::::::::::b     33333333:::::3  d::::::::::::::::d  \n"
	@printf "\033[38;5;202mC:::::C              u::::u    u::::u  b:::::bbbbb:::::::b    3:::::::::::3  d:::::::ddddd:::::d  \n"
	@printf "\033[38;5;196mC:::::C              u::::u    u::::u  b:::::b    b::::::b    33333333:::::3 d::::::d    d:::::d  \n"
	@printf "\033[38;5;160mC:::::C              u::::u    u::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d  \n"
	@printf "\033[38;5;124mC:::::C              u::::u    u::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d  \n"
	@printf "\033[38;5;88m C:::::C       CCCCCCu:::::uuuu:::::u  b:::::b     b:::::b            3:::::3d:::::d     d:::::d  \n"
	@printf "\033[38;5;52m  C:::::CCCCCCCC::::Cu:::::::::::::::uub:::::bbbbbb::::::b3333333     3:::::3d::::::ddddd::::::dd \n"
	@printf "\033[38;5;52m   CC:::::::::::::::C u:::::::::::::::ub::::::::::::::::b 3::::::33333::::::3 d:::::::::::::::::d \n"
	@printf "\033[38;5;52m     CCC::::::::::::C  uu::::::::uu:::ub:::::::::::::::b  3:::::::::::::::33   d:::::::::ddd::::d \n"
	@printf "\033[38;5;52m        CCCCCCCCCCCCC    uuuuuuuu  uuuubbbbbbbbbbbbbbbb    333333333333333      ddddddddd   ddddd \n"
	@printf "\033[0m\n"
	@printf "                                                                         by: \033[38;5;82mjquinodo && rtari-ca\033[0m\n"

# ASCII animation intro
