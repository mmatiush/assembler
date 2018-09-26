#include "libft.h"
#include "op.h"
#include "asm.h"

void	validate_assembly(t_asm *a)
{
	int		index;

	index = 0;
	while(a->list)
	{
		
		a->list = a->list->next;
	}
}
