#include "libft.h"
#include "op.h"
#include "asm.h"

void	validate_header(t_data *list, header_t *header)
{
	char *name;
	char *comment;

	name = NULL;
	comment = NULL;
	while(list && (name == NULL || comment == NULL))
	{
		
		if (!(ft_strncmp(list->data, NAME_CMD_STRING, 5)
		{
			
		}
		if(name)
		list = list->next;
	}

}