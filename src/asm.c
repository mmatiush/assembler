#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Create a linked list where each node is one line from the .s file
*/

int		assembler(char *name)
{
	t_list		*list;
	header_t	header;

	read_data(&list, name);
	validate_header(list, header);
	//проверить валидность листа, создать файл и записывать все в него;
	return (1);
}
