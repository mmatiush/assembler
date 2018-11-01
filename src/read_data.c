/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:53:49 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:08:53 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"
#include <fcntl.h>

static void		null_rest_of_string(char *str)
{
	while (*str != EOL)
		*str = '\0';
}

/*
** Removes COMMENT_CHARs and ';' and everything following it
** but not in COMMENT_CMD_STRING that is separated by
** DBL_QUOTATION_CHAR
*/

static void		remove_comments(char *str, int *quotations)
{
	if (str != NULL && *str != EOL)
	{
		while (*str != EOL)
		{
			if (*str == DBL_QUOTATION_CHAR)
				(*quotations)++;
			else if ((*str == COMMENT_CHAR || *str == ';') && \
					(*quotations % 2) != OPEN)
			{
				null_rest_of_string(str);
				return ;
			}
			str++;
		}
	}
}

int				ft_strisempty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

/*
** Reads data from the file while removing all comments
** starting with the COMMENT_CHAR or ';'.
** Quotations can be either open or closed.
** If they are open, the function will add '\n' to the end of each line
*/

void			read_data(t_asm *a, const char *name)
{
	int			line_num;
	char		*buff;
	int			fd;
	int			quotations;

	quotations = CLOSED;
	buff = NULL;
	line_num = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		exit(print_error(2));
	while (get_next_line(fd, &buff) > 0 && ++line_num)
	{
		remove_comments(buff, &quotations);
		if (quotations > 4)
			exit(print_error_line(3, line_num));
		if (quotations % 2 == OPEN)
			add_to_list(a, ft_strjoin(buff, "\n"), line_num);
		else if (!ft_strisempty(buff))
		{
			add_to_list(a, buff, line_num);
			continue ;
		}
		free(buff);
	}
	a->list_head = a->list;
}
