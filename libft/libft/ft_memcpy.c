/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:53:13 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/04 18:53:15 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;

	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
