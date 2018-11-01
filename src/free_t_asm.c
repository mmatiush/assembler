/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:27:45 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:59:36 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void		free_labels(t_labels *label_ptr)
{
	t_labels	*label;
	t_ops		*op;

	while (label_ptr)
	{
		label = label_ptr;
		free(label->name);
		while (label->ops)
		{
			op = label->ops;
			label->ops = label->ops->next;
			free(op);
		}
		label_ptr = label_ptr->next;
		free(label);
	}
}

static void		free_label_refences(t_asm *a)
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

void			free_t_asm(t_asm *a)
{
	free_labels(a->labels);
	free_label_refences(a);
	free(a->header);
	free_list(&a->list_head);
}
