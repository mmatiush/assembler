/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:39:16 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/07 12:39:18 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cs;

	cs = (unsigned char*)s;
	while (n--)
	{
		if (*cs++ == (unsigned char)c)
			return (--cs);
	}
	return (NULL);
}
