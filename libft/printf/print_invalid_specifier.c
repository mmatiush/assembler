/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:35:53 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:35:58 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_invalid_specifier(t_flags *f)
{
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), f);
	ft_putchar(f->specifier);
	f->num_printed++;
	if (f->minus)
		print_padding(f->width, 1, ' ', f);
}
