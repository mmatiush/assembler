/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:36:28 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/25 23:53:53 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	start_printing(t_flags *f)
{
	if (f->specifier == 'D' || f->specifier == 'U' || f->specifier == 'O')
		f->l = 1;
	if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'D')
		print_decimal(f);
	(f->specifier == 'u' || f->specifier == 'U') ? print_unsigned(f) : 0;
	(f->specifier == 'o' || f->specifier == 'O') ? print_octal(f) : 0;
	(f->specifier == 'c') ? print_char(f) : 0;
	(f->specifier == 'C') ? print_wchar(f) : 0;
	(f->specifier == 's') ? print_str(f) : 0;
	(f->specifier == 'S') ? print_wstr(f) : 0;
	(f->specifier == 'x' || f->specifier == 'X') ? print_hexadecimal(f) : 0;
	(f->specifier == '%') ? print_percent(f) : 0;
	(f->specifier == 'b') ? print_binary(f) : 0;
	if (f->specifier == 'p')
	{
		f->hash = 1;
		f->j = 1;
		print_hexadecimal(f);
	}
	if (!equals_spec(f->specifier) && f->specifier)
		print_invalid_specifier(f);
}

int			ft_printf(const char *format, ...)
{
	t_flags	f;

	f.fmt = format;
	f.num_printed = 0;
	va_start(f.ap, format);
	while (*f.fmt)
	{
		if (*f.fmt != '%')
		{
			ft_putchar(*f.fmt);
			f.num_printed++;
		}
		else
		{
			clr_flags(&f);
			f.fmt++;
			read_format_1(&f);
			start_printing(&f);
		}
		f.fmt++;
	}
	return (f.num_printed);
}
