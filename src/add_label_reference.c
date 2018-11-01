/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:47:07 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:49:17 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void		add_label_reference(t_asm *a, char *label_name, size_t index)
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
