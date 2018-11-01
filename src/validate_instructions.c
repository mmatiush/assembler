/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:25:43 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:21:07 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void		trim_op_params(char **params_arr)
{
	int		i;

	i = 0;
	if (params_arr == NULL)
		return ;
	while (params_arr[i])
	{
		params_arr[i] = ft_strtrim_free(params_arr[i]);
		i++;
	}
}

static void		check_params_num(t_asm *a, size_t params_num)
{
	if ((int)params_num != a->cur_op->op_ptr->nb_params)
		exit(print_error_line(5, a->list->line_num));
}

/*
** The line is splitted by a SEPARATOR_CHAR. In the first element of the
** array will be the instruction and its first parameter.
*/

static void		handle_line_without_label(t_asm *a, char *data)
{
	size_t	params_num;
	char	**params_arr;

	params_num = ft_occurnum(data, SEPARATOR_CHAR) + 1;
	if (!(params_arr = ft_strsplit(data, SEPARATOR_CHAR)))
		exit(print_error_line(12, a->list->line_num));
	trim_op_params(params_arr);
	params_arr[0] = handle_op_and_return_first_param(a, params_arr[0]);
	params_arr[0] = ft_strtrim_free(params_arr[0]);
	check_params_num(a, params_num);
	handle_op_params(a, params_arr, params_num);
}

static void		handle_full_line(t_asm *a, char *data)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (data[i])
	{
		if (!ft_strchr(LABEL_CHARS, data[i]))
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
	while (a->list)
	{
		a->cur_op = NULL;
		handle_full_line(a, a->list->data);
		if (a->cur_op)
		{
			if (a->cur_label->end_byte == a->cur_label->start_byte)
				a->cur_label->end_byte = a->cur_label->end_byte + \
				get_op_size(a->cur_op) - 1;
			else
				a->cur_label->end_byte = a->cur_label->end_byte + \
				get_op_size(a->cur_op);
		}
		a->list = a->list->next;
	}
}
