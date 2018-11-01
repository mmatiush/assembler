/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:01:06 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:52:48 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

size_t			get_op_size(t_ops *op)
{
	int		i;
	size_t	size;

	if (!op)
		return (0);
	size = 1;
	if (op->codage)
		size += 1;
	i = 0;
	while (i < NEW_MAX_OP_ARGS_NUMBER)
	{
		size += op->param_size[i];
		i++;
	}
	return (size);
}

static void		null_t_ops_struct(t_ops *op)
{
	int i;

	op->next = NULL;
	op->codage = 0;
	op->op_ptr = NULL;
	i = 0;
	while (i < NEW_MAX_OP_ARGS_NUMBER)
	{
		op->param[i] = 0;
		op->param_size[i] = 0;
		i++;
	}
}

void			add_op(t_asm *a, t_op *op_ptr)
{
	t_ops		*temp;

	if (!(temp = malloc(sizeof(t_ops))))
		exit(print_error(4));
	null_t_ops_struct(temp);
	temp->op_ptr = op_ptr;
	if (a->cur_label->ops == NULL)
	{
		temp->start_byte = a->cur_label->start_byte;
		a->cur_label->ops = temp;
		a->cur_op = temp;
	}
	else
	{
		a->cur_op = a->cur_label->ops;
		while (a->cur_op->next != NULL)
			a->cur_op = a->cur_op->next;
		temp->start_byte = a->cur_label->end_byte + 1;
		a->cur_op->next = temp;
		a->cur_op = a->cur_op->next;
	}
}

static size_t	get_op_name_len(t_asm *a, char *data)
{
	size_t		len;

	len = 0;
	while (ft_strchr(LABEL_CHARS, data[len]))
	{
		len++;
	}
	if (data[len] == EOL)
		exit(print_error_line(5, a->list->line_num));
	return (len);
}

char			*handle_op_and_return_first_param(t_asm *a, char *data)
{
	int		i;
	size_t	len;
	char	*op_name;
	char	*param;

	i = 0;
	if (!(len = get_op_name_len(a, data)))
		exit(print_error_line(13, a->list->line_num));
	op_name = ft_strndup(data, len);
	param = ft_strdup(data + len);
	free(data);
	while (g_op_tab[i].name != NULL)
	{
		if (!(ft_strcmp(g_op_tab[i].name, op_name)))
		{
			add_op(a, &g_op_tab[i]);
			free(op_name);
			return (param);
		}
		i++;
	}
	exit(print_error_line(14, a->list->line_num));
}
