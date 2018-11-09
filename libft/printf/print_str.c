/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:36:19 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:36:21 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_flags *f)
{
	char		*str;
	unsigned	len;

	if (f->l)
	{
		print_wstr(f);
		return ;
	}
	str = va_arg(f->ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (f->f_prcsn)
		(f->prcsn < len) ? len = f->prcsn : 0;
	if (!f->minus)
		print_padding(f->width, len, (f->zero ? '0' : ' '), f);
	write(1, str, len);
	f->num_printed = f->num_printed + len;
	if (f->minus)
		print_padding(f->width, len, ' ', f);
}
