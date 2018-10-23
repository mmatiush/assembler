#ifndef ASM_H
# define ASM_H
# include "op.h"
# include <stddef.h>
# include <stdint.h>

# define EMPTY		0
# define EOL		'\0'
# define TRUE		1
# define FALSE		0

# define CLOSED 	0
# define OPEN		1

# define NAME		1
# define CMNT		2

#define NEW_IND_SIZE	2
#define NEW_REG_SIZE	1

#define NEW_MAX_OP_ARGS_NUMBER	3

typedef struct      s_op
{
    char            *name;
    int             nb_params;
	t_arg_type		param[NEW_MAX_OP_ARGS_NUMBER];
	int				op_code;
	int				codage;
	int				label_size;
}                   t_op;

typedef struct		s_data
{
	char			*data;
	int				line_num;
	struct s_data	*next;			
}					t_data;

typedef struct		s_ops
{
	t_op			*op_ptr;
	u_int32_t		codage;
	u_int32_t		param[NEW_MAX_OP_ARGS_NUMBER];
	u_int8_t		param_size[NEW_MAX_OP_ARGS_NUMBER];
	u_int32_t		start_byte;
	struct s_ops	*next;
}					t_ops;

typedef struct		s_labels
{
	char			*name;
	u_int32_t		start_byte;
	u_int32_t		end_byte;
	t_ops			*ops;
	struct s_labels	*next;
}					t_labels;

typedef struct		s_lebel_ref t_label_ref;

struct				s_lebel_ref
{
	t_ops			*op;
	u_int32_t		param_index;
	char			*lable_name;
	t_label_ref		*next;
};

typedef struct		s_asm
{
	t_data			*list;
	t_header		*header;
	t_labels		*labels;
	t_labels		*cur_label;
	t_ops			*cur_op;
	t_label_ref		*label_ref;
}					t_asm;

typedef int			t_bool;

t_op				g_op_tab[17];

int		assembler(char *name);

int		print_error(const int error_num);
int		print_error_line(const int error_num, const int line);
int		print_err_line_param(const int error_num, const int line, char *name);

void	read_data(t_asm *a, const char *name);
void	add_to_list(t_asm *a, char *buff, const int line_num);
void	free_list(t_data **list);
void	print_list(t_data *list);

void	validate_header(t_asm *a);

int		ft_strisempty(char *str);

void	trim_remaining_list_strings(t_data *list);

void	validate_instructions(t_asm *a);


/*
** Label handling
*/

void	add_empty_start_label(t_asm *a);
void	add_label(t_asm *a, char *data, size_t i);

/*
** Instruction handling
*/

char	*handle_op_and_return_first_param(t_asm *a, char *data);
void	add_op(t_asm *a, t_op *op_ptr);
size_t	get_op_size(t_ops *op);


/*
** Instruction params handling
*/

void	handle_op_params(t_asm *a, char **params_arr, size_t params_num);


#endif
