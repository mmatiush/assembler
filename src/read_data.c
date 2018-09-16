#include "libft.h"
#include "op.h"
#include "asm.h"
#include <fcntl.h>

static void		null_rest_of_string(char *str)
{
	while(*str != EOL)
		*str = '\0';
}


/*
** Removes COMMENT_CHARs and everything following it
** but not in COMMENT_CMD_STRING that is separated by
** DBL_QUOTATION_CHAR
*/


static void		remove_comments(char *str, int *quotations)
{
	if (str != NULL && *str != EOL)
	{
		while(*str != EOL)
		{
			if (*str == DBL_QUOTATION_CHAR)
			{
				(*quotations)++;
				str++;
				continue ;
			}
			if (*str == COMMENT_CHAR && *quotations % 2 != OPEN)
			{
				null_rest_of_string(str);
				return ;
			}
			str++;
		}
	}
}

add_to_list(t_list **list, const char *buff, const int line_num)
{
	t_list		*temp;

	temp->data = buff;
	temp->line_num = line_num;
	
}

/*
** Reads data from the file while removing all comments
** starting with the COMMENT_CHAR.
** Quotations can be either open or closed.
*/

void			read_data(t_list **list, const char *name)
{
	int			line_num;
	char		*buff;
	int			fd;
	int			quotations;

	quotations = CLOSED;
	buff = NULL;
	line_num = 0;
	if (fd = open(name, O_RDONLY))
		return(print_error(2));
	while(get_next_line(fd, &buff) > 0)
	{
		line_num++;
		remove_comments(buff, &quotations);
		if(quotations > 4)
			exit(print_error_line(3, line_num));
		if (buff != EMPTY && buff[0] != EOL)
			add_to_list(list, buff, line_num);
		else
			add_to_list(list, "\n", line_num);
		}
		free(buff);
}
