/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:59:46 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/07 12:59:48 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*cs1++ - *cs2++)
			return (*--cs1 - *--cs2);
	}
	return (0);
}
