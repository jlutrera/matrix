# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourlogin <yourlogin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 00:00:00 by yourlogin         #+#    #+#              #
#    Updated: 2025/01/01 00:00:00 by yourlogin        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = matrix_tests

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -Iinclude

SRC_DIR     = src
TEST_DIR    = test
OBJ_DIR     = obj

SRC         = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC    = $(wildcard $(TEST_DIR)/*.cpp)
MAIN_SRC   	= main.cpp

OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ    = $(TEST_SRC:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)
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

$(NAME): $(OBJ) $(TEST_OBJ) $(MAIN_OBJ)
		@echo "$(BLUE)Linking $(NAME)...$(RESET)"
		@$(CXX) $(CXXFLAGS) $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) -o $(NAME)
		@echo "$(GREEN)✅ Tests compilados$(RESET)"

# Crear carpeta obj si no existe
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

# Compilación de src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		@echo "$(YELLOW)Compilando $<...$(RESET)"
		@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de test/
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
		@echo "$(YELLOW)Compilando test $<...$(RESET)"
		@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de main.cpp
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
		@echo "$(YELLOW)Compilando main.cpp...$(RESET)"
		@$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

run: $(NAME)
		@echo "$(BLUE)Ejecutando tests...$(RESET)"
		@./$(NAME)

clean:
		@echo "$(RED)Eliminando objetos...$(RESET)"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@echo "$(RED)Eliminando ejecutable...$(RESET)"
		@rm -f $(NAME)
re: fclean all

# ===========================
#         MODO DEBUG
# ===========================

debug: CXXFLAGS += -g3 -fsanitize=address
debug: re
		@echo "$(GREEN)✅ Compilado en modo DEBUG$(RESET)"

# ===========================
#         PHONY
# ===========================

.PHONY: all clean fclean re run debug
