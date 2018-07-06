/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:34:25 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/07 18:34:26 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*cdst;
	const char	*csrc;
	size_t		n;
	size_t		dstlen;

	n = dstsize;
	cdst = dst;
	csrc = src;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dstlen = dst - cdst;
	n = dstsize - dstlen;
	if (n-- == 0)
		return (dstlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dstlen + (src - csrc));
}
