/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:12:55 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 20:12:56 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Makes a string from unsigned long int a base.
** The third agrument is either 'A' or 'a'. It will affect the case:
** either abcdef or ABCDEF. For base <= 10 it's ignored.
*/

char	*ft_lutoa_base(size_t value, int base, char c)
{
	char	*s;
	size_t	n;
	int		i;

	n = value;
	i = 1;
	while ((value /= base) > 0)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
		n /= base;
	}
	return (s);
}
