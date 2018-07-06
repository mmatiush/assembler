/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:49:14 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:49:16 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Fxxx - font color; Bxxx - background color.
*/

# define AOFF "\x1B[0m"

# define FBLK "\x1B[30m"
# define FRED "\x1B[31m"
# define FGRN "\x1B[32m"
# define FYEL "\x1B[33m"
# define FBLU "\x1B[34m"
# define FMAG "\x1B[35m"
# define FCYN "\x1B[36m"
# define FWHT "\x1B[37m"

# define BBLK "\x1B[40m"
# define BRED "\x1B[41m"
# define BGRN "\x1B[42m"
# define BYEL "\x1B[43m"
# define BBLU "\x1B[44m"
# define BMAG "\x1B[45m"
# define BCYN "\x1B[46m"
# define BWHT "\x1B[47m"

/*
** Axxx - text attributes;
** Off all attributes, bold, low intensity, underscore
** reverse color and background
*/

# define AOFF "\x1B[0m"
# define ABLD "\x1B[1m"
# define ALWI "\x1B[2m"
# define AUND "\x1B[4m"
# define ARVR "\x1B[7m"

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	const char	*fmt;
	va_list		ap;
	int			num_printed;

	char		specifier;
	unsigned	width;
	unsigned	prcsn;

	unsigned	hash:1;
	unsigned	minus:1;
	unsigned	plus:1;
	unsigned	zero:1;
	unsigned	space:1;
	unsigned	f_prcsn:1;

	unsigned	hh:1;
	unsigned	h:1;
	unsigned	ll:1;
	unsigned	l:1;
	unsigned	j:1;
	unsigned	z:1;
}				t_flags;

void			clr_flags(t_flags *f);
int				equals_spec(const char c);
void			read_format_1(t_flags *f);
char			*ft_lutoa_base(size_t value, int base, char c);

/*
** c, C
*/

void			print_char(t_flags *f);
void			print_padding(unsigned width, unsigned print_len, char symbol\
				, t_flags *f);
void			print_wchar(t_flags *f);
size_t			ft_putwchar(wchar_t wc);
unsigned		get_wclen(wchar_t wc);
void			ft_wctomb(unsigned char *octet, wchar_t wc, int wc_len);

/*
** s, S
*/

void			print_str(t_flags *f);
void			print_wstr(t_flags *f);

/*
**	d, i
*/

void			print_decimal(t_flags *f);

/*
**	u, U
*/

void			print_unsigned(t_flags *f);
size_t			get_unsigned_fl(t_flags *f);

/*
** %
*/

void			print_percent(t_flags *f);

/*
** o, O
*/

void			print_octal(t_flags *f);

/*
** x, X
*/

void			print_hexadecimal(t_flags *f);

/*
** b
*/

void			print_binary(t_flags *f);

/*
** Invalid sepcifier
*/

void			print_invalid_specifier(t_flags *f);

#endif
