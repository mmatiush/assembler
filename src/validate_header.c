#include "libft.h"
#include "op.h"
#include "asm.h"

void		if_name_comment_exist(int flag)
{
	if (!(flag & NAME))
		exit(print_error(6));
	else if (!(flag & CMNT))
		exit(print_error(7));
}

static int	quotations_num(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str == '"')
			i++;
		str++;
	}
	return (i);
}

static void	add_prog_name_to_struct (char *dest, char *src, int *flag)
{
	int		i;

	i = 0;
	while (src && src[i])
	{
		if (i == PROG_NAME_LENGTH)
			exit (print_error(8));
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*flag = *flag | NAME;
}

static void	add_prog_comment_to_struct (char *dest, char *src, int *flag)
{
	int		i;

	i = 0;
	while (src && src[i])
	{
		if (i == COMMENT_LENGTH)
			exit (print_error(9));
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*flag = *flag | CMNT;
}
/*
** Check if there is not extra characters after the 
*/
int			good_cmnt(char *str)
{
	if (ft_strisempty(ft_strrchr(str, '"') + 1))
		return (1);
	else
		return (0);
}

char	*get_cmd_beginning(char *str)
{
	char	**arr;
	char	*temp;

	arr = ft_strsplit(str, '"');
	temp = ft_strdup(arr[1]);
	ft_free_str_arr(&arr);
	return (temp);
}

void		read_cmd_str_from_several_lines(t_asm *a, char *dest, void (*f)(char *, char *, int *), int *flag)
{
	char	*temp;
	char	*buff;
	char	**arr;
	int		quot_num;

	temp = get_cmd_beginning(a->list->data);
	while((a->list = a->list->next))
	{
		quot_num = quotations_num(a->list->data);
		if (quot_num == 0)
		{
			buff = ft_strjoin(temp, a->list->data);
			free(temp);
			temp = buff;
		}
		else if (quot_num == 1)
		{
			if (!good_cmnt(a->list->data))
				exit (print_error_line(5, a->list->line_num));
			arr = ft_strsplit(a->list->data, '"');
			buff = ft_strjoin(temp, arr[0]);
			free(temp);
			temp = buff;
			ft_free_str_arr(&arr);
			break ;
		}
		else
			exit (print_error_line(5, a->list->line_num));
	}
	if (quot_num == 0)
		exit(print_error(5));
	f(dest, temp, flag);
	free(temp);
}


static void	read_header_string(t_asm *a, char **arr, int *flag, int quot_num)
{
	if (quot_num == 2)
	{
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME && good_cmnt(a->list->data))
			add_prog_name_to_struct(a->header->prog_name, arr[1], flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT && good_cmnt(a->list->data))
			add_prog_comment_to_struct(a->header->comment, arr[1], flag);
		else
			exit(print_error_line(5, a->list->line_num));
	}
	else if (quot_num == 1)
	{
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME)
			read_cmd_str_from_several_lines(a, a->header->prog_name, &add_prog_name_to_struct, flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT)
			read_cmd_str_from_several_lines(a, a->header->comment, &add_prog_comment_to_struct, flag);
		else
			exit(print_error_line(5, a->list->line_num));
	}
}

void	validate_header(t_asm *a)
{
	int		flag;
	char	**arr;
	int		quot_num;

	flag = EMPTY;
	while(a->list && (!(flag & NAME) || !(flag & CMNT)))
	{
		arr = ft_strsplit(a->list->data, '"');
		arr[0] = ft_strtrim_free(arr[0]);
		quot_num = quotations_num(a->list->data);
		if (quot_num == 2 || quot_num == 1)
			read_header_string(a, arr, &flag, quot_num);
		else
			exit (print_error_line(5, a->list->line_num));
		ft_free_str_arr(&arr);
		a->list = a->list->next;
	}
	if_name_comment_exist(flag);
}
