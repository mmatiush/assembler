/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:34:09 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 19:34:10 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function to check specifier. Returns 1 if char equals one of the sepcifiers.
*/

int			equals_spec(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||\
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%' ||\
		c == 'b')
		return (1);
	else
		return (0);
}

/*
** Read fomat started when a % was encountered. It will process while format
** doesn't equal a specifier and while format exists
*/

static void	read_wildcard(t_flags *f)
{
	int	n;

	if (!f->f_prcsn)
	{
		n = va_arg(f->ap, int);
		(n < 0) ? f->minus = 1 : 0;
		f->width = (n < 0) ? -(unsigned)n : (unsigned)n;
	}
	else
	{
		n = va_arg(f->ap, int);
		if (n < 0)
		{
			f->prcsn = 0;
			f->f_prcsn = 0;
		}
		else
			f->prcsn = n;
	}
}

static void	read_format_2(t_flags *f, const char *prev_format)
{
	(*f->fmt == 'j') ? f->j = 1 : 0;
	(*f->fmt == 'z') ? f->z = 1 : 0;
	(f->hh) ? f->h = 0 : 0;
	(f->ll) ? f->l = 0 : 0;
	(*f->fmt == '#') ? f->hash = 1 : 0;
	(*f->fmt == '-') ? f->minus = 1 : 0;
	(*f->fmt == '+') ? f->plus = 1 : 0;
	(*f->fmt == '0') ? f->zero = 1 : 0;
	(*f->fmt == ' ') ? f->space = 1 : 0;
	if (ft_isdigit(*f->fmt) && *f->fmt != '0' && *prev_format == '.')
	{
		f->prcsn = ft_atoi(f->fmt);
		while (ft_isdigit(*f->fmt))
			f->fmt++;
		f->fmt--;
	}
	if (ft_isdigit(*f->fmt) && *f->fmt != '0' && *prev_format != '.')
	{
		f->width = ft_atoi(f->fmt);
		while (ft_isdigit(*f->fmt))
			f->fmt++;
		f->fmt--;
	}
	f->fmt++;
}

/*
** Read_format checks format string while encounters any of characters that
** may represent flags or modifiers
*/

void		read_format_1(t_flags *f)
{
	const char	*prev_format;

	while (*f->fmt && ft_strchr("hljz0#+-. *1234567890", *f->fmt))
	{
		prev_format = f->fmt - 1;
		if (*f->fmt == '.')
		{
			(f->f_prcsn = 1);
			(f->prcsn = 0);
		}
		if (*f->fmt == '*')
			read_wildcard(f);
		(*f->fmt == 'h' && f->h) ? f->hh = 1 : 0;
		(*f->fmt == 'l' && f->l) ? f->ll = 1 : 0;
		(*f->fmt == 'h') ? f->h = 1 : 0;
		(*f->fmt == 'l') ? f->l = 1 : 0;
		read_format_2(f, prev_format);
	}
	if (*f->fmt)
		f->specifier = *f->fmt;
	else
		f->fmt--;
}
