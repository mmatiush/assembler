#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

int		assembler(char *name)
{
	t_asm	a;
	t_data	*list;
	a.list = NULL;
	a.header = (t_header*)malloc(sizeof(t_header));

	read_data(&a, name);
	list = a.list;
	validate_header(&a);
	trim_remaining_list_strings(a.list);
	print_list(a.list);
	ft_printf("\n->[%s]<-\n", a.header->prog_name);
	ft_printf("\n->[%s]<-\n\n", a.header->comment);
	// validate_assembly(&a);
	free(a.header);
	free_list(&list);
	//проверить валидность листа, создать файл и записывать все в него;
	// system ("leaks asm");
	return (0);
}
