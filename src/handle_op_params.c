/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:01:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:50:00 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

static void		handle_t_ind(t_asm *a, char *param_name, size_t param_index)
{
	int		n;

	if (!(a->cur_op->op_ptr->param[param_index] & T_IND))
		exit(print_err_line_param(15, a->list->line_num, param_name));
	if (param_name[0] == LABEL_CHAR)
		add_label_reference(a, param_name + 1, param_index);
	else
	{
		n = ft_atoi(param_name);
		if (check_number_param(param_name))
			exit(print_err_line_param(15, a->list->line_num, param_name - 1));
		a->cur_op->param[param_index] = (unsigned)n;
	}
	if (a->cur_op->op_ptr->codage)
		add_codage(a, IND_CODE, param_index);
	a->cur_op->param_size[param_index] = NEW_IND_SIZE;
}

static void		handle_t_dir(t_asm *a, char *param_name, size_t param_index)
{
	int		n;

	if (!(a->cur_op->op_ptr->param[param_index] & T_DIR))
		exit(print_err_line_param(15, a->list->line_num, param_name - 1));
	if (param_name[0] == LABEL_CHAR)
		add_label_reference(a, param_name + 1, param_index);
	else
	{
		n = ft_atoi(param_name);
		if (check_number_param(param_name))
			exit(print_err_line_param(15, a->list->line_num, param_name - 1));
		a->cur_op->param[param_index] = (unsigned)n;
	}
	if (a->cur_op->op_ptr->codage)
		add_codage(a, DIR_CODE, param_index);
	a->cur_op->param_size[param_index] = a->cur_op->op_ptr->label_size;
}

static void		handle_t_reg(t_asm *a, char *param_name, size_t param_index)
{
	int		n;

	if (!(a->cur_op->op_ptr->param[param_index] & T_REG))
		exit(print_err_line_param(15, a->list->line_num, param_name - 1));
	if (!(ft_isdigit(param_name[0])))
		exit(print_err_line_param(12, a->list->line_num, param_name - 1));
	n = ft_atoi(param_name);
	if (ft_intlen(n) != ft_strlen(param_name))
		exit(print_err_line_param(15, a->list->line_num, param_name - 1));
	a->cur_op->param[param_index] = n;
	a->cur_op->param_size[param_index] = NEW_REG_SIZE;
	if (a->cur_op->op_ptr->codage)
		add_codage(a, REG_CODE, param_index);
}

static void		handle_one_param(t_asm *a, char *param_name, size_t param_index)
{
	if (param_name == NULL)
		exit(print_error_line(13, a->list->line_num));
	if (param_name[0] == REG_CHAR)
		handle_t_reg(a, param_name + 1, param_index);
	else if (param_name[0] == DIRECT_CHAR)
		handle_t_dir(a, param_name + 1, param_index);
	else
		handle_t_ind(a, param_name, param_index);
}

void			handle_op_params(t_asm *a, char **params_arr, size_t params_num)
{
	size_t i;

	i = 0;
	while (i < params_num)
	{
		handle_one_param(a, params_arr[i], i);
		free(params_arr[i]);
		i++;
	}
	free(params_arr);
}
