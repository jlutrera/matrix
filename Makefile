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

NAME        = 	matrix

CXX         = 	c++
CXXFLAGS    = 	-Wall -Wextra -Werror -Iinclude

SRC_DIR     = 	src
OBJ_DIR     = 	obj

SRC         = 	$(wildcard $(SRC_DIR)/*.cpp)
OBJ         = 	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# ===========================
#          COLORES
# ===========================

GREEN       = 	\033[0;32m
BLUE        = 	\033[0;34m
YELLOW      = 	\033[1;33m
RED         = 	\033[0;31m
RESET       = 	\033[0m

# ===========================
#          REGLAS
# ===========================

all			: 	$(NAME)

$(NAME)		: 	$(OBJ)
				@echo "$(BLUE)Linking $(NAME)...$(RESET)"
				@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
				@echo "$(GREEN)All test compiled$(RESET)"

$(OBJ_DIR)	:
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
				@echo "$(YELLOW)Compiling $<...$(RESET)"
				@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
				@echo "$(RED)Deleting objets...$(RESET)"
				@rm -rf $(OBJ_DIR)

fclean		:	clean
				@echo "$(RED)Deleting executable...$(RESET)"
				@rm -f $(NAME)

re			: 	fclean all

# ===========================
#         MODO DEBUG
# ===========================

debug		: 	CXXFLAGS += -g3 -fsanitize=address
debug		: 	re
				@echo "$(GREEN)Compiled in DEBUG mode$(RESET)"

# ===========================
#         PHONY
# ===========================

.PHONY		: 	all clean fclean re debug
