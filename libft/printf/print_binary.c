/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:04:38 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** Prints unsigned long int in binary.
*/

void	print_binary(t_flags *f)
{
	size_t		value;
	char		*s;
	unsigned	len;

	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 2, 'a');
	if (value == 0 && f->f_prcsn)
	{
		free(s);
		s = NULL;
	}
	len = (ft_strlen(s) > f->prcsn) ? ft_strlen(s) : f->prcsn;
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus && !f->zero)
		print_padding(f->width, len, ' ', f);
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len, '0', f);
	if (f->prcsn > ft_strlen(s))
		print_padding(f->prcsn, ft_strlen(s), '0', f);
	write(1, s, ft_strlen(s));
	if (f->minus)
		print_padding(f->width, len, ' ', f);
	f->num_printed += ft_strlen(s);
	ft_strdel(&s);
}
