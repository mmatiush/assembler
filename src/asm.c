/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:35:03 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/09 18:03:19 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

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
