/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:36:59 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:37:01 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hexadecimal_pref(size_t value, t_flags *f)
{
	if (f->hash && f->specifier == 'x' && value != 0)
		return ("0x");
	else if (f->hash && f->specifier == 'X' && value != 0)
		return ("0X");
	else if (f->specifier == 'p')
		return ("0x");
	else
		return ("");
}

void		print_hexadecimal(t_flags *f)
{
	size_t		value;
	char		*s;
	unsigned	len;
	char		*prefix;

	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 16, (f->specifier == 'X') ? 'A' : 'a');
	prefix = get_hexadecimal_pref(value, f);
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = (ft_strlen(s) > f->prcsn) ? ft_strlen(s) : f->prcsn;
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus && !f->zero)
		print_padding(f->width, len + ft_strlen(prefix), ' ', f);
	write(1, prefix, ft_strlen(prefix));
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len + ft_strlen(prefix), '0', f);
	if (f->prcsn > ft_strlen(s))
		print_padding(f->prcsn, ft_strlen(s), '0', f);
	write(1, s, ft_strlen(s));
	if (f->minus)
		print_padding(f->width, len + ft_strlen(prefix), ' ', f);
	f->num_printed += ft_strlen(s) + ft_strlen(prefix);
	ft_strdel(&s);
}
