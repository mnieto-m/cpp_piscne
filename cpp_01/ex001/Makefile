NAME = zombie

# Variables generales
CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = rm
RMFLAGS = -rf
MKDIR = mkdir -p
INCLUDE = -I$(INCLUDE_DIR)

# Directorios

SRC_DIR = src/
OBJ_DIR = bin/obj/
BIN_DIR = bin/
INCLUDE_DIR = include/

#Files
FILES = main\
		zombie\
		zombieHorde
# FILES_ADD

SRC = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# 1ª RULE
all:  $(NAME)

# Comp bin
$(NAME): $(OBJ) $(LIBFT_NAME)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME) 

# Comp .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
# clean OBJ
clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)

# clean binary OBJ
fclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR) $(NAME)

# Recompilar todo
re: fclean all 

.PHONY: all clean fclean libmlx