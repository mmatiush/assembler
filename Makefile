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
SRC		:= asm.c op.c main.c read_data.c add_data_to_list.c error_handling.c \
		trim_remaining_list_strings.c validate_header.c validate_instructions.c \
		handle_label.c handle_ops.c handle_op_params.c fill_label_references.c

OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Header files
INC	:= asm.h

# Compiler and flags
CC		:= gcc -g
FLAGS	:= -Wall -Wextra -Werror

# Compile and link the program
all: lib obj_dir $(NAME)

# Link object files into the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) -I $(INC_DIR) -I $(LIBFT_INC)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(INC_DIR), $(INC))
	$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIBFT_INC)

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

run: all
	./asm zork.s

# GNU will run even if files have names as instructions
.PHONY: all clean fclean re
