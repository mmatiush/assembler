/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label_references.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:06:22 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/24 17:28:25 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

unsigned	get_label_start(t_asm *a , char *name, int const line_num)
{
	t_labels *lable_ptr;

	lable_ptr = a->labels;
	while (lable_ptr)
	{
		if (ft_strequ(lable_ptr->name, name))
			return (lable_ptr->start_byte);
		lable_ptr = lable_ptr->next;
	}
	exit(print_err_line_param(16, line_num, name));
}

void		fill_label_references(t_asm *a)
{
	t_label_ref *ref;
	unsigned	label_start_byte;

	ref = a->label_ref;
	while (ref)
	{
		label_start_byte = get_label_start(a, ref->lable_name, ref->line_num);
		ref->op->param[ref->param_index] = label_start_byte - ref->op->start_byte;
		ft_printf("START: %x SIZE: %d\n", ref->op->param[ref->param_index], ref->op->param_size[ref->param_index]);
		ref = ref->next;
	}
}

void		free_label_refences(t_asm *a)
{
	t_label_ref *ref;

	while (a->label_ref)
	{
		ref = a->label_ref;
		a->label_ref = a->label_ref->next;
		free(ref->lable_name);
		free(ref);
	}
}

void	print_lebel_ref(t_label_ref *ref)
{
	ft_printf("\n\n");
	while(ref)
	{
		ft_printf("OP %s refers to LB %s\n", ref->op->op_ptr->name, ref->lable_name);
		ref = ref->next;
	}
}

