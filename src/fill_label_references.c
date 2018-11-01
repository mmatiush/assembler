/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label_references.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:06:22 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:40:03 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static unsigned	get_label_start(t_asm *a, char *name, int const line_num)
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

void			fill_label_references(t_asm *a)
{
	t_label_ref *ref;
	unsigned	label_start_byte;

	ref = a->label_ref;
	while (ref)
	{
		label_start_byte = get_label_start(a, ref->lable_name, ref->line_num);
		ref->op->param[ref->param_index] = label_start_byte - \
											ref->op->start_byte;
		ref = ref->next;
	}
}
