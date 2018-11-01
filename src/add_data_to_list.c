/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:36:08 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 18:36:30 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

void	add_to_list(t_asm *a, char *buff, const int line_num)
{
	t_data		*temp;
	t_data		*current_node;

	if (!(temp = (t_data*)malloc(sizeof(t_data))))
		exit(print_error(5));
	temp->data = buff;
	temp->line_num = line_num;
	temp->next = NULL;
	if (a->list == NULL)
	{
		a->list = temp;
		return ;
	}
	current_node = a->list;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = temp;
}

void	free_list(t_data **list)
{
	t_data	*temp;

	while (*list != NULL)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->data);
		temp->data = NULL;
		free(temp);
		temp = NULL;
	}
}

void	print_list(t_data *list)
{
	while (list != NULL)
	{
		ft_printf("[%d -> %s]\n", list->line_num, list->data);
		list = list->next;
	}
}
