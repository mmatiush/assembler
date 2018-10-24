#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

void	print_instructions(t_asm *a)
{
	t_labels *lbl = a->labels;
	t_ops *op;
	while (lbl)
	{
		op = lbl->ops;
		ft_printf("\tL:<%s>\n", lbl->name);
		while (op)
		{
			ft_printf("startByte<%u> endByte<%u> OPSTART<%u> Codage:<%0.8b> OP:<%s> Param:<%d><%d><%d>\n", lbl->start_byte, lbl->end_byte, op->start_byte, op->codage, op->op_ptr->name, op->param[0], op->param[1], op->param[2]);
			op = op->next;
		}
		lbl = lbl->next;
	}
}

void	free_labels(t_labels *label_ptr)
{
	t_labels	*label;
	t_ops		*op;

	while(label_ptr)
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

int		assembler(char *name)
{
	t_asm	a;
	t_data	*list_to_free;
	
	a.cur_op = NULL;
	a.cur_label = NULL;
	a.labels = NULL;
	a.list = NULL;
	a.label_ref = NULL;
	a.header = (t_header*)malloc(sizeof(t_header));

	read_data(&a, name);
	list_to_free = a.list;
	validate_header(&a);
	trim_remaining_list_strings(a.list);
	ft_printf("\n");
	print_list(a.list);
	ft_printf("\n->[%s]<-\n", a.header->prog_name);
	ft_printf("\n->[%s]<-\n\n", a.header->comment);
	validate_instructions(&a);

	fill_label_references(&a);
	print_instructions(&a);
	free_label_refences(&a);
	free_labels(a.labels);
	free(a.header);
	free_list(&list_to_free);
	//проверить валидность листа, создать файл и записывать все в него;
	return (0);
}
