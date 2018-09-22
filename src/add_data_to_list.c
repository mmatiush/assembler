#include "libft.h"
#include "op.h"
#include "asm.h"

void	add_to_list(t_data **list, char *buff, const int line_num)
{
	t_data		*temp;
	t_data		*current_node;

	if (!(temp = (t_data*)malloc(sizeof(t_data))))
		exit(print_error(5));
	temp->data = buff;
	temp->line_num = line_num;
	temp->next = NULL;
	if (*list == NULL)
	{
		*list = temp;
		return ;
	}
	current_node = *list;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = temp;
}

void	free_list(t_data **list)
{
	if (*list != NULL)
		free_list(&(*list)->next);
	free((*list)->data);
	free(*list);
	*list = NULL;
}

void	print_list(t_data *list)
{
	while (list != NULL)
	{
		ft_printf("[%d -> %s]\n", list->line_num, list->data);
		list = list->next;
	}
}