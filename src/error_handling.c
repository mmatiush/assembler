/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:36:42 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/13 19:48:40 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static char	*g_error_text[] =
{
	"Wrong number of parameters\n\tUsage: ./asm <filenme.s>",
	"Wrong file extension\n\tUsage: ./asm <filenme.s>",
	"Failed file opening",
	"Extra [ \" ]",
	"Couldn't allocate memory",
	"Syntax error",
	"Missing .name",
	"Missing .comment",
	"Champion name too long (Max length 128)",
	"Champion comment too long (Max length 2048)",
	"Wrong parameters",
	"Failed file creating",
	"Lexical error",
	"Operation syntax error",
	"Invalid instruction",
	"Invalid parameter for the instruction",
	"Undefined reference to label",
	"Champion has no instructions"
};

int		print_error(const int error_num)
{
	ft_printf("Error: %s\n", g_error_text[error_num]);
	return (-1);
}

int		print_error_line(const int error_num, const int line)
{
	ft_printf("Error:\nLine #%d - %s\n", line, g_error_text[error_num]);
	return (-1);
}

int		print_err_line_param(const int error_num, const int line, char *name)
{
	ft_printf("Error:\nLine #%d, parameter < %s > - %s\n", \
			line, name, g_error_text[error_num]);
	return (-1);
}
