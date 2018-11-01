/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:35:03 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:36:19 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

/*
**static void	print_instructions(t_asm *a)
**{
**	t_labels *lbl = a->labels;
**	t_ops *op;
**	while (lbl)
**	{
**		op = lbl->ops;
**		ft_printf("\tL:<%s>\n", lbl->name);
**		while (op)
**		{
**			ft_printf("startByte<%u> endByte<%u> OPSTART<%u> Codage:<%0.8b> \
** OP:<%s> Param:<%d><%d><%d>\n", lbl->start_byte, lbl->end_byte, \
** op->start_byte,\
** op->codage, op->op_ptr->name, op->param[0], op->param[1], op->param[2]);
**			op = op->next;
**		}
**		lbl = lbl->next;
**	}
**}
**
**static void	print_lebel_ref(t_label_ref *ref)
**{
**	ft_printf("\n\n");
**	while(ref)
**	{
**		ft_printf("OP %s refers to LB %s\n", ref->op->op_ptr->name, \
**  ref->lable_name);
**		ref = ref->next;
**	}
**}
*/

static void		null_t_asm_struct(t_asm *a)
{
	a->header = (t_header*)malloc(sizeof(t_header));
	a->header->magic = COREWAR_EXEC_MAGIC;
	a->cur_op = NULL;
	a->cur_label = NULL;
	a->labels = NULL;
	a->list = NULL;
	a->label_ref = NULL;
}

static void		write_prog_size(t_asm *a)
{
	if (!a->labels->next && !a->labels->ops)
		exit(print_error(17));
	if (a->cur_label->ops)
		a->header->prog_size = a->cur_label->end_byte + 1;
	else
		a->header->prog_size = a->cur_label->end_byte;
}

int				assembler(char *name)
{
	t_asm	a;

	null_t_asm_struct(&a);
	read_data(&a, name);
	validate_header(&a);
	trim_remaining_list_strings(a.list);
	validate_instructions(&a);
	write_prog_size(&a);
	fill_label_references(&a);
	write_to_output_file(&a, name);
	free_t_asm(&a);
	return (0);
}
