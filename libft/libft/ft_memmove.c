/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:52:39 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/07 07:52:41 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	if (src < dst)
		while (len--)
			cdst[len] = csrc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
