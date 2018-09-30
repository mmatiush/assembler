#include "libft.h"
#include "op.h"
#include "asm.h"

void	add_label(data, len)
{
	char	*label;

	label = (char *)malloc(sizeof(char) * (len + 1));
	ft_strncpy(label, data, len);
}

void	add_op();

void	parse_string(t_asm a, char *data, int line_num)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data[i + j])
	{
		if (!ft_strchr(LABEL_CHARS, data[i]))
		{
			if (data[i] == LABEL_CHAR)
			{
				add_label(a, i);
				while (data[i + j])
				{
					if (!ft_strchr(LABEL_CHARS, data[i + j]))

				}
			}
			else
				add_op();
		}
		else ()
		i++;
	}
}

void	validate_ops(t_asm *a)
{
	while(a->list)
	{

		parse_string(a->list->data, a->list->line_num);
		a->list = a->list->next;
	}
}

/**
 * считать до не ЛЕЙБЛЧАРА
 * 	если : - записать начало нового лейбла
 *  если не 2 точки, то начать сверять с struct of ops names
 *	else (exit_error)
 * 
 * /
