/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_header_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:49:55 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:11:32 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void		if_name_comment_exist(int flag)
{
	if (!(flag & NAME))
		exit(print_error(6));
	else if (!(flag & CMNT))
		exit(print_error(7));
}

int			quotations_num(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str == '"')
			i++;
		str++;
	}
	return (i);
}

/*
** Check if there is not extra characters after the \"
*/

int			good_cmnt(char *str)
{
	if (ft_strisempty(ft_strrchr(str, '"') + 1))
		return (1);
	else
		return (0);
}

void		add_prog_name_to_struct(char *dest, char *src, int *flag)
{
	int		i;

	i = 0;
	while (src && src[i])
	{
		if (i == PROG_NAME_LENGTH)
			exit(print_error(8));
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*flag = *flag | NAME;
}

void		add_prog_comment_to_struct(char *dest, char *src, int *flag)
{
	int		i;

	i = 0;
	while (src && src[i])
	{
		if (i == COMMENT_LENGTH)
			exit(print_error(9));
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*flag = *flag | CMNT;
}
