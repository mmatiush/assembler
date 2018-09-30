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

typedef int			t_bool;
typedef struct		s_header t_header;

typedef struct		s_data
{
	int				line_num;
	char			*data;
	struct s_data	*next;			
}					t_data;

typedef struct		s_labels
{
	char			*name;
	size_t			address;
	int				byte;
	struct s_labels	*next;
}					t_labels;

typedef struct		s_asm
{
	t_data			*list;
	t_header		*header;
	t_labels		*label;
	int				labels_num;
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