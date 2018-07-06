/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:35:42 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:35:44 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	get_decimal_fl(t_flags *f)
{
	ssize_t	value;

	if (f->j)
		value = va_arg(f->ap, intmax_t);
	else if (f->z)
		value = va_arg(f->ap, size_t);
	else if (f->l)
		value = va_arg(f->ap, long int);
	else if (f->ll)
		value = va_arg(f->ap, long long int);
	else if (f->h)
		value = (short)va_arg(f->ap, int);
	else if (f->hh)
		value = (char)va_arg(f->ap, int);
	else
		value = va_arg(f->ap, int);
	return (value);
}

static char		*get_decimal_pref(ssize_t value, t_flags *f)
{
	char	*prefix;

	if (value < 0)
		prefix = "-";
	else if (value >= 0 && f->plus)
		prefix = "+";
	else if (value >= 0 && f->space && !f->plus)
		prefix = " ";
	else
		prefix = "";
	return (prefix);
}

void			print_decimal(t_flags *f)
{
	ssize_t			value;
	char			*s;
	unsigned		len;
	char			*prefix;

	value = get_decimal_fl(f);
	s = ft_lutoa_base((value < 0) ? -(size_t)value : (size_t)value, 10, 'a');
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = (ft_strlen(s) > f->prcsn) ? ft_strlen(s) : f->prcsn;
	prefix = get_decimal_pref(value, f);
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
