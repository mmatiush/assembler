/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:56:29 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/06 16:56:38 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*csrc;
	unsigned char		*cdst;

	cdst = dst;
	csrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i++] == (unsigned char)c)
		{
			return (dst + i);
		}
	}
	return (NULL);
}
