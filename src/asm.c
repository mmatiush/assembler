#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

int		assembler(char *name)
{
	t_asm	a;
	a.list = NULL;
	a.header = NULL;

	read_data(&a.list, name);
	// head = list;
	print_list(a.list);
	free_list(&a.list);
	// list = validate_header(&list, &header);
	//проверить валидность листа, создать файл и записывать все в него;
	// system ("leaks asm");
	return (0);
}
