# Name of the program
NAME	:= asm

# Directories
OBJ_DIR	:= ./obj/
SRC_DIR	:= ./src/
INC_DIR := ./inc/

LIBFT_DIR :=	./libft/
LIBFT_INC :=	./libft/inc/
LIBFT := 		$(LIBFT_DIR)libft.a

# Source and object files
SRC		:= 
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

# Header files
INC	:= 

# Compiler and flags
CC		:= gcc -g
FLAGS	:= -Wall -Wextra -Werror

# Compile and link the program
all: lib obj_dir $(NAME)

# Link object files into the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(addprefix $(INC_DIR), $(INC))
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR) -I $(LIBFT_INC)

# Compile my library
lib:
	@make -C $(LIBFT_DIR)

# Create a directory for object files
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Delete object files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Delete all files created with the Makefile
fclean:
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean

# Re-make all files
re: fclean all

# GNU will run even if files have names as instructions
.PHONY: all clean fclean re