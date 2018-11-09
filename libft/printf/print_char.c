/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:36:48 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:36:50 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_flags *f)
{
	if (f->l)
	{
		print_wchar(*&f);
		return ;
	}
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), &*f);
	ft_putchar(va_arg(f->ap, int));
	f->num_printed++;
	if (f->minus)
		print_padding(f->width, 1, ' ', &*f);
}
