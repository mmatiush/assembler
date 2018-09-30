#include "libft.h"
#include "asm.h"

void	trim_remaining_list_strings(t_data *list)
{
	while(list)
	{
		list->data = ft_strtrim_free(list->data);
		list = list->next;
	}
}