#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

int		assembler(char *name)
{
	t_asm	a;
	t_data	*head;
	a.list = NULL;
	a.header = (t_header*)malloc(sizeof(t_header));

	read_data(&a, name);
	head = a.list;
	print_list(a.list);
	validate_header(&a);
	ft_printf("\n->[%s]<-\n", a.header->prog_name);
	ft_printf("\n->[%s]<-\n\n", a.header->comment);
	free_list(&a.list);
	//проверить валидность листа, создать файл и записывать все в него;
	// system ("leaks asm");
	return (0);
}
