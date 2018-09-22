#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

int		assembler(char *name)
{
	t_data		*list;
	// t_data		*head;
	// header_t	header;
// 
	list = NULL;
	read_data(&list, name);
	free_list(&list);
	// head = list;
	print_list(list);
	// list = validate_header(&list, &header);
	//проверить валидность листа, создать файл и записывать все в него;
	system ("leaks asm");
	return (0);
}
