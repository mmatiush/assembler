#ifndef ASM_H
# define ASM_H

# define EMPTY		0
# define EOL		'\0'
# define TRUE		1
# define FALSE		0

# define CLOSED 	0
# define OPEN		1

# define NAME		1
# define CMNT		2

t_op				g_op_tab[17];


typedef int			t_bool;
typedef struct		s_header t_header;

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
	u_int32_t		param[3];
	u_int8_t		param_size[3];
	// u_int32_t		par1;
	// u_int8_t		par1_size;
	// u_int32_t		par2;
	// u_int8_t		par2_size;
	// u_int32_t		par3;
	// u_int8_t		par3_size;
	u_int32_t		start_byte;
	u_int32_t		end_byte;
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

typedef struct		s_asm
{
	t_data			*list;
	t_header		*header;
	t_labels		*labels;
	t_labels		*cur_label;
	t_ops			*cur_op;
	t_ops			*label_ref;
}					t_asm;

int		assembler(char *name);

int		print_error(const int error_num);
int		print_error_line(const int error_num, const int line);

void	read_data(t_asm *a, const char *name);
void	add_to_list(t_asm *a, char *buff, const int line_num);
void	free_list(t_data **list);
void	print_list(t_data *list);

void	validate_header(t_asm *a);

int		ft_strisempty(char *str);

void	trim_remaining_list_strings(t_data *list);



#endif


void	trim_op_params(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		arr[i] = ft_strtrim_free(arr[i]);
		i++;
	}
}