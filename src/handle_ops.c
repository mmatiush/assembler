/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:01:06 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/19 18:53:16 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

size_t	get_op_size(t_ops *ops)
{
	if (!ops)
		return (0);
	size_t	size;

	size = 0;
	if (ops->codage)
		size += 1;
	size += ops->par1_size;
	size += ops->par2_size;
	size += ops->par3_size;

}


void	add_op(t_asm *a, t_op *op_ptr)
{
	t_ops		*temp;
	
	if (!(temp = malloc(sizeof(t_ops))))
		exit(print_error(11));
	
	temp->next = NULL;

	if (a->cur_label->ops == NULL)
	{
		temp->start_byte = a->cur_label->start_byte;
		a->cur_label->ops = temp;
		a->cur_op = temp;
	}
	else
	{
		temp->start_byte = a->cur_op->end_byte + 1;
		a->cur_op->next = temp;
		a->cur_op = a->cur_op->next;
	}

}

/* TODO: not relevant
** The first element of arr will contain an Operation and its first parameter
**/

void	handle_op_param()
{
	if 
}

void	handle_op_and_return_first_param(t_asm *a, char *data)
{
	int		i;
	size_t	size;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		size = ft_strlen(g_op_tab[i].name);
		if (!(ft_strncmp(g_op_tab[i].name, data, size)))
		{

		}

		i++;
	}
}


