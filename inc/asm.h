#ifndef ASM_H
# define ASM_H

# define EMPTY		0
# define EOL		'\0'
# define CLOSED 	0
# define OPEN		1

typedef struct		s_data
{
	int				line_num;
	char			*data;
	struct s_data	*next;			
}					t_data;

int		assembler(char *name);

int		print_error(const int error_num);
int		print_error_line(const int error_num, const int line);

void	read_data(t_data **list, const char *name);
void	add_to_list(t_data **list, char *buff, const int line_num);
void	free_list(t_data **list);

void	print_list(t_data *list);


#endif