/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:01:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/24 20:35:08 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

static void		add_codage(t_asm *a, size_t reg, size_t param_index)
{
	if (param_index == 0)
		a->cur_op->codage += (reg << 6);
	else if (param_index == 1)
		a->cur_op->codage += (reg << 4);
	else if (param_index == 2)
		a->cur_op->codage += (reg << 2);
	else
		exit(-1);
}

static void		add_label_reference(t_asm *a, char *label_name, size_t index)
{
	t_label_ref *temp;
	t_label_ref *head;

	if (!(temp = malloc(sizeof(t_label_ref))))
		exit(print_error(4));

	temp->lable_name = ft_strdup(label_name);
	temp->op = a->cur_op;
	temp->param_index = index;
	temp->line_num = a->list->line_num;
	temp->next = NULL;

	if (a->label_ref == NULL)
	{
		a->label_ref = temp;
		return ;
	}
	head = a->label_ref;
	while (head->next != NULL)
		head = head->next;
	head->next = temp;
}

static void		handle_T_IND(t_asm *a, char *param_name, size_t param_index)
{
	int		n;
	char	*temp;
	
	if (!(a->cur_op->op_ptr->param[param_index] & T_IND))
		exit(print_err_line_param(15, a->list->line_num, param_name));
	if (param_name[0] == LABEL_CHAR)
		add_label_reference(a, param_name + 1, param_index);
	else
	{
		n = ft_atoi(param_name);
		temp = ft_itoa(n);
		if (ft_strcmp(param_name, temp))
			exit(print_err_line_param(15, a->list->line_num, param_name));
		free(temp);
		a->cur_op->param[param_index] = (unsigned)n;
	}

	if (a->cur_op->op_ptr->codage)
		add_codage(a, T_IND, param_index);
	
	a->cur_op->param_size[param_index] = NEW_IND_SIZE;

}

static void		handle_T_DIR(t_asm *a, char *param_name, size_t param_index)
{
	int		n;
	char	*temp;

	if (!(a->cur_op->op_ptr->param[param_index] & T_DIR))
		exit(print_err_line_param(15, a->list->line_num, param_name - 1));
	if (param_name[0] == LABEL_CHAR)
		add_label_reference(a, param_name + 1, param_index);
	else
	{
		n = ft_atoi(param_name);
		temp = ft_itoa(n);
		if (ft_strcmp(param_name, temp))
			exit(print_err_line_param(15, a->list->line_num, param_name - 1));
		free(temp);
		a->cur_op->param[param_index] = (unsigned)n;
	}
	if (a->cur_op->op_ptr->codage)
		add_codage(a, T_DIR, param_index);

	a->cur_op->param_size[param_index] = a->cur_op->op_ptr->label_size;
}

static void		handle_T_REG(t_asm *a, char *param_name, size_t param_index)
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
		add_codage(a, T_REG, param_index);
}

static void		handle_one_param(t_asm *a, char *param_name, size_t param_index)
{
	if (param_name == NULL)
		exit(print_error_line(13, a->list->line_num));
	if (param_name[0] == REG_CHAR)
		handle_T_REG(a, param_name + 1, param_index);
	else if (param_name[0] == DIRECT_CHAR)
		handle_T_DIR(a, param_name + 1, param_index);
	else
		handle_T_IND(a, param_name, param_index);
}

void			handle_op_params(t_asm *a, char **params_arr, size_t params_num)
{
	size_t i;

	i = 0;
	while (i < params_num)
	{
		handle_one_param(a, params_arr[i], i);
		free (params_arr[i]);
		i++;
	}
	free(params_arr);
	// TODO: check if all params were placed;
}
