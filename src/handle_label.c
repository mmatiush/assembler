/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:01:14 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:03:58 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Start and end bytes and -1 to be able to get instruction ending byte
** by adding the size of the operation like in validate_instructions() function
*/

void	add_empty_start_label(t_asm *a)
{
	t_labels	*temp;

	if (!(temp = malloc(sizeof(t_labels))))
		exit(print_error(4));
	temp->name = NULL;
	temp->next = NULL;
	temp->ops = NULL;
	temp->start_byte = 0;
	temp->end_byte = 0;
	a->labels = temp;
	a->cur_label = temp;
}

void	add_label(t_asm *a, char *data, size_t i)
{
	t_labels	*temp;

	if (!(temp = malloc(sizeof(t_labels))))
		exit(print_error(4));
	temp->name = ft_strndup(data, i);
	temp->next = NULL;
	temp->ops = NULL;
	if (a->cur_label->start_byte != a->cur_label->end_byte)
	{
		temp->start_byte = a->cur_label->end_byte + 1;
		temp->end_byte = temp->start_byte;
	}
	else
	{
		temp->start_byte = a->cur_label->end_byte;
		temp->end_byte = temp->start_byte;
	}
	a->cur_label->next = temp;
	a->cur_label = a->cur_label->next;
}
