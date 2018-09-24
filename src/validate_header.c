#include "libft.h"
#include "op.h"
#include "asm.h"

// char		*ft_strtrim_start(char *str)
// {
// 	int		trim_len;
// 	int		i;
// 	char	*temp;

// 	if (!str)
// 		return (str);
// 	trim_len = 0;
// 	while(str[trim_len] == '\t' || str[trim_len] == ' ')
// 		trim_len++;
// 	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - trim_len + 1))))
// 		exit(print_error(4));
// 	i = 0;
// 	while (str[trim_len])
// 		temp[i++] = str[trim_len++];
// 	temp[i] = '\0';
// 	free(str);
// 	return (temp);
// }

// char		*ft_strtrim_end(char *str)
// {
// 	int		len;

// 	if (!str)
// 		return (str);
// 	len = ft_strlen(str);
// 	while (--len >= 0)
// 	{
// 		if (str[len] == '\t' || str[len] == ' ')
// 			str[len] = '\0';
// 		else
// 			break ;
// 	}
// 	return (str);
// }

void		if_name_comment_exist(int flag)
{
	if (flag & NAME)
		exit(print_error(6));
	if (flag & CMNT)
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


char	*ft_strtrim_free(char *str) // TODO: add to lib
{
	char *temp;
	
	if (!str)
		return (str);
	temp = ft_strtrim(str);
	free(str);
	return (temp);
}

static void	add_prog_name_to_struct (char *dest, char *src, int *flag)
{
	int		i;

	i = 0;
	while (src[i])
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
	while (src[i])
	{
		if (i == COMMENT_LENGTH)
			exit (print_error(9));
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*flag = *flag | CMNT;
}

void		read_cmd_str_from_several_lines(t_asm *a, char *dest, char *src, void (*f)(char *, char *, int *), int *flag)
{
	char	*temp;
	char	*buff;
	int		i;
	int		quot_num;
	char	**arr;

	i = 0;
	temp = ft_strdup(src);
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
			arr = ft_strsplit(a->list->data, '"');
			if (arr[0] && ft_strisempty(arr[1]))
			{
				buff = ft_strjoin(temp, arr[0]);
				free(temp);
				temp = buff;
			}
			else
				exit (print_error_line(5, a->list->line_num));
			ft_free_str_arr(&arr);
		}
		else
			exit (print_error_line(5, a->list->line_num));
	}
	f(dest, temp, flag);
	free(temp);
}


static void	read_header_string(t_asm *a, char **arr, int *flag, int quot_num)
{
	if (quot_num == 2)
	{
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME && arr[1] && ft_strisempty(arr[2]))
			add_prog_name_to_struct(a->header->prog_name, arr[1], flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT && arr[1] && ft_strisempty(arr[2]))
			add_prog_comment_to_struct(a->header->comment, arr[1], flag);
		else
			exit(print_error_line(5, a->list->line_num));
	}
	else if (quot_num == 1)
	{
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME)
			read_cmd_str_from_several_lines(a, a->header->prog_name, arr[1], &add_prog_name_to_struct, flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT)
			read_cmd_str_from_several_lines(a, a->header->comment, arr[1], &add_prog_comment_to_struct, flag);
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
