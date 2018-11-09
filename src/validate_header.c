/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:29:38 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/09 18:54:59 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static char	*get_cmd_beginning(char *str)
{
	char	**arr;
	char	*temp;

	arr = ft_strsplit(str, '"');
	temp = ft_strdup(arr[1]);
	ft_free_str_arr(&arr);
	return (temp);
}

static int	add_end_of_line(t_asm *a, char **temp, char *buff)
{
	char	**arr;

	if (!good_cmnt(a->list->data))
		exit(print_error_line(5, a->list->line_num));
	arr = ft_strsplit(a->list->data, '"');
	buff = ft_strjoin(*temp, arr[0]);
	free(*temp);
	*temp = buff;
	ft_free_str_arr(&arr);
	return (1);
}

static void	read_cmd_str_from_several_lines(t_asm *a, char *dest, \
						void (*f)(char *, char *, int *), int *flag)
{
	char	*temp;
	char	*buff;
	int		quot_num;

	temp = get_cmd_beginning(a->list->data);
	while ((a->list = a->list->next))
	{
		quot_num = quotations_num(a->list->data);
		if (quot_num == 0)
		{
			buff = ft_strjoin(temp, a->list->data);
			free(temp);
			temp = buff;
		}
		else if (quot_num == 1 && add_end_of_line(a, &temp, buff))
			break ;
		else
			exit(print_error_line(5, a->list->line_num));
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
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME && \
				good_cmnt(a->list->data))
			add_prog_name_to_struct(a->header->prog_name, arr[1], flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT && \
				good_cmnt(a->list->data))
			add_prog_comment_to_struct(a->header->comment, arr[1], flag);
		else
			exit(print_error_line(5, a->list->line_num));
	}
	else if (quot_num == 1)
	{
		if (!ft_strcmp(arr[0], NAME_CMD_STRING) && *flag != NAME)
			read_cmd_str_from_several_lines(a, a->header->prog_name, \
											&add_prog_name_to_struct, flag);
		else if (!ft_strcmp(arr[0], COMMENT_CMD_STRING) && *flag != CMNT)
			read_cmd_str_from_several_lines(a, a->header->comment, \
											&add_prog_comment_to_struct, flag);
		else
			exit(print_error_line(5, a->list->line_num));
	}
}

void		validate_header(t_asm *a)
{
	int		flag;
	char	**arr;
	int		quot_num;

	flag = EMPTY;
	while (a->list && (!(flag & NAME) || !(flag & CMNT)))
	{
		arr = ft_strsplit(a->list->data, '"');
		arr[0] = ft_strtrim_free(arr[0]);
		quot_num = quotations_num(a->list->data);
		if (quot_num == 2 || quot_num == 1)
			read_header_string(a, arr, &flag, quot_num);
		else
			exit(print_error_line(5, a->list->line_num));
		ft_free_str_arr(&arr);
		a->list = a->list->next;
	}
	if_name_comment_exist(flag);
}
