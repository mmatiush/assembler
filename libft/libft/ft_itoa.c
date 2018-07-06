/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:39:39 by mmatiush          #+#    #+#             */
/*   Updated: 2018/01/16 16:27:49 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				ilen;
	unsigned int	n_cpy;

	n_cpy = n;
	ilen = ft_intlen(n);
	if (n < 0)
	{
		n_cpy = -n;
		ilen++;
	}
	if (!(str = ft_strnew(ilen)))
		return (NULL);
	str[--ilen] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--ilen] = n_cpy % 10 + '0';
	if (n < 0)
		str[--ilen] = '-';
	return (str);
}
