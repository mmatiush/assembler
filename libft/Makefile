NAME :=			libft.a

PRINTF_DIR :=	./printf/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/

SRC := ft_printf.c clr_flags.c print_char.c print_invalid_specifier.c \
print_decimal.c print_unsigned.c print_percent.c print_octal.c \
print_hexadecimal.c print_padding.c print_str.c print_wchar.c \
print_wstr.c read_format_string.c ft_lutoabase.c print_binary.c

LIBFT_SRC := ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_memset.c\
ft_strchr.c ft_strrchr.c ft_strcmp.c ft_atoi.c ft_isdigit.c ft_memalloc.c \
ft_strnew.c ft_strdel.c ft_strequ.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_itoa.c ft_putchar.c ft_putnbr.c ft_strwdnb.c ft_isspace.c \
ft_intlen.c ft_bzero.c get_next_line.c ft_free_str_arr.c ft_strisint.c \
ft_strndup.c ft_swap_uint_bytes.c ft_swap_ushort_bytes.c ft_is_big_endian.c \
ft_occurnum.c

LIBFT_DIR :=	./libft/

OBJ :=			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT_OBJ :=	$(addprefix $(OBJ_DIR), $(LIBFT_SRC:.c=.o))

CC_FLAGS :=		-Wall -Wextra -Werror

CC :=			gcc -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ]

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR)
	@echo "Linking lib" [ $< ]

$(OBJ_DIR)%.o: $(LIBFT_DIR)%.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR)
	@echo "Linking lib" [ $< ]

clean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@echo "Cleaning" [ object files $(NAME) ]

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
