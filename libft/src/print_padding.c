/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:36:09 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:36:12 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The function accepts width flag, length of print parameter, padding
** symbol ' ' or '0', pointer to structure.
** The function prints width - print_len bytes;
*/

void	print_padding(unsigned width, unsigned print_len, char symbol,\
		t_flags *f)
{
	while (print_len < width)
	{
		ft_putchar(symbol);
		print_len++;
		f->num_printed++;
	}
}
