#ifndef ASM_H
# define ASM_H

# define EMPTY		0
# define EOL		'\0'
# define CLOSED 	0
# define OPEN		1

typedef struct		s_list
{
	int				line_num;
	char			*data;
	struct s_list	*next;			
}					t_list;


int		print_error(const int error_num);
int		print_error_line(const int error_num, const int line);

void	read_data(t_list **list, const char *name);




#endif