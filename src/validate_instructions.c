/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:25:43 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/19 19:02:29 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

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


void	check_params_num(t_asm *a, size_t num)
{
	int i;

	i = 0;
	while (i < num)
	{
		if (a->cur_op->op_ptr->param[i] == NULL)
			exit(print_error_line(12, a->list->line_num));
	}
}

void	handle_line_without_label(t_asm *a, char *data)
{
	size_t	param_num;
	int		i;
	char	**arr;
	t_op	*op;

	param_num = comma_num(data) + 1;
	arr = ft_strsplit(data, SEPARATOR_CHAR);
	trim_op_params(arr);
	arr[0] = handle_op_and_return_first_param(arr[0]);
	check_params_num(a, num);
	i = 0;
	while (i <= param_num)
	{
		handle_op_param(arr[i], i);
	}
}

void	handle_full_line(t_asm *a, char *data)
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

void	validate_instructions(t_asm *a)
{
	add_empty_start_label(a);

	while(a->list)
	{
		handle_full_line(a, a->list->data);
		if (a->cur_op)
		{
			a->cur_op->end_byte = get_op_size(a->cur_op) - 1;
			a->cur_label->end_byte = a->cur_op->end_byte;
		}
		a->list = a->list->next;
	}
}
