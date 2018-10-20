/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:25:43 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/20 19:39:15 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

static int	comma_num(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	return (i);
}

static void		trim_op_params(char **arr)
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

static void		check_params_num(t_asm *a, size_t param_num)
{
	size_t i;

	i = 0;

	if (param_num > NEW_MAX_OP_ARGS_NUMBER)
		exit(print_error_line(5, a->list->line_num));
	while (i < param_num)
	{
		if (a->cur_op->op_ptr->param[i] == 0)
			exit(print_error_line(12, a->list->line_num));
		i++;
	}
}

static void		handle_line_without_label(t_asm *a, char *data)
{
	size_t	param_num;
	size_t	i;
	char	**arr;

	param_num = comma_num(data) + 1;
	arr = ft_strsplit(data, SEPARATOR_CHAR);
	trim_op_params(arr);
	arr[0] = handle_op_and_return_first_param(a, arr[0]);
	arr[0] = ft_strtrim_free(arr[0]);
	check_params_num(a, param_num);
	i = 0;
	while (i < param_num)
	{
		handle_op_param(a, arr[i], i);
		i++;
	}
}

static void		handle_full_line(t_asm *a, char *data)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (data[i])
	{
		if (!ft_strchr(LABEL_CHARS, data[i])) // если попадаем на НЕ лейбл чар
		{
			if (data[i] == LABEL_CHAR)
			{
				add_label(a, data, i);
				if (data[i + 1] != EOL)
					handle_line_without_label(a, &data[i + 1]);
			}
			else
				handle_line_without_label(a, data);
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		exit(print_error_line(5, a->list->line_num));
}

void			validate_instructions(t_asm *a)
{
	add_empty_start_label(a);

	while(a->list)
	{
		a->cur_op = NULL;
		handle_full_line(a, a->list->data);
		if (a->cur_op)
		{
			a->cur_op->end_byte = get_op_size(a->cur_op) - 1;
			a->cur_label->end_byte = a->cur_op->end_byte;
		}
		a->list = a->list->next;
	}
}
