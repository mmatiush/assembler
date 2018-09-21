#include "libft.h"
#include "op.h"
#include "asm.h"

char		*ft_strtrim_start(char *str)
{
	int		trim_len;
	int		i;
	char	*temp;

	if (!str)
		return (str);
	trim_len = 0;
	while(str[trim_len] == '\t' || str[trim_len] == ' ')
		trim_len++;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - trim_len + 1))))
		exit(print_error(4));
	i = 0;
	while (str[trim_len])
		temp[i++] = str[trim_len++];
	temp[i] = '\0';
	free(str);
	return (temp);
}

char		*ft_strtrim_end(char *str)
{
	int		len;

	if (!str)
		return (str);
	len = ft_strlen(str);
	while (--len >= 0)
	{
		if (str[len] == '\t' || str[len] == ' ')
			str[len] = '\0';
		else
			break ;
	}
	return (str);
}

void		if_name_comment_exist(bool_t fl_name, bool_t fl_comment)
{
	if (fl_name == FALSE)
		exit(print_error(6));
	if (fl_comment == FALSE)
		exit(print_error(7));
}

static int	check_if_line_empty(char *str)
{
	if(!str)
		return (0);
	while(*str)
	{
		if (*str != ' ' || *str != '\n' || *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

check_ending()
{

}

t_data*		read_CMD_comment(t_data *list, header_t *header)
{

}

t_data*		read_CMD_name(t_data *list, header_t *header)
{
	char	*str;
	int		quotations;
	int		i;

	// i = 0;
	// quotations = CLOSED;
	// str = list->data + ft_strlen(NAME_CMD_STRING);
	while(list)
	{
		while(str)
		{
			
			// if (quotations == CLOSED)
			// {
			// 	if (*str == ' ' || *str == '\t')
			// 		str++;
			// 	else if (*str != ' ' && *str != '\t')
			// 		exit();
			// }
			// else if (quotations == OPEN)
			// {
			// 	header->prog_name[i++] = *str;sd
			// }
			// str++;
		}
		list = list->next;
		str = list->data;
	}
	return(list);
}

t_data*	validate_header(t_data *list, header_t *header)
{
	bool_t	fl_name;
	bool_t	fl_comment;

	fl_name == FALSE;
	fl_comment == FALSE;
	while(list && (fl_name == FALSE || fl_comment == FALSE))
	{
		list->data = ft_strtrim_start(list->data);
		if (!ft_strncmp(list->data, NAME_CMD_STRING, 5) && fl_name == FALSE)
		{
			list = read_CMD_string(list, header->prog_name);
			fl_name = TRUE;
		}
		else if (!ft_strncmp(list->data, COMMENT_CMD_STRING, 5) && fl_comment == FALSE)
		{
			list = read_CMD_string(list, header->comment);
			fl_comment = TRUE;
		}
		else if (check_if_line_empty(list->data))
			exit(print_error_line(5, list->line_num)); // дописать
		else
			exit(ft_printf("THIS SHOULD NEVER HAPPEN. VALIDATE_HEADER\n")); //  remove ME TODO:
		if (list)
			list = list->next;
	}
	if_name_comment_exist(fl_name, fl_comment);
	return (list);
}