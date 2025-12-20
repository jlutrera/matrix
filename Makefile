# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 11:33:29 by jutrera-          #+#    #+#              #
#    Updated: 2025/12/20 11:33:29 by jutrera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = matrix

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -Iinclude

SRC_DIR     = src
OBJ_DIR     = obj

SRC         = $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SRC   	= main.cpp

OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
MAIN_OBJ    = $(OBJ_DIR)/main.o

# ===========================
#          COLORES
# ===========================

GREEN       = \033[0;32m
BLUE        = \033[0;34m
YELLOW      = \033[1;33m
RED         = \033[0;31m
RESET       = \033[0m

# ===========================
#          REGLAS
# ===========================

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
		@echo "$(BLUE)Linking $(NAME)...$(RESET)"
		@$(CXX) $(CXXFLAGS) $(OBJ) $(MAIN_OBJ) -o $(NAME)
		@echo "$(GREEN)All test compiled$(RESET)"

# Crear carpeta obj si no existe
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

# Compilación de src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		@echo "$(YELLOW)Compiling $<...$(RESET)"
		@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de main.cpp
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
		@echo "$(YELLOW)Compiling main.cpp...$(RESET)"
		@$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

run: $(NAME)
		@./$(NAME)

clean:
		@echo "$(RED)Deleting objets...$(RESET)"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@echo "$(RED)Deleting executable...$(RESET)"
		@rm -f $(NAME)
re: fclean all

# ===========================
#         MODO DEBUG
# ===========================

debug: CXXFLAGS += -g3 -fsanitize=address
debug: re
		@echo "$(GREEN)Compiled in DEBUG mode$(RESET)"

# ===========================
#         PHONY
# ===========================

.PHONY: all clean fclean re run debug
