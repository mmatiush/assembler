/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:37:17 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:37:18 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_flags *f)
{
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), f);
	write(1, "%", 1);
	f->num_printed++;
	if (f->minus)
		print_padding(f->width, 1, ' ', f);
}
