/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:25:05 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/23 13:25:08 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Function counts and returns the bumber of words in a string. A word is
** a sequence of printing chars except spaces
*/

size_t		ft_strwdnb(const char *s)
{
	size_t	res;
	size_t	sym;

	res = 0;
	sym = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (ft_ischrctr(*s))
		{
			sym = 1;
			s++;
		}
		res += (sym == 1) ? 1 : 0;
		sym = 0;
		if (*s != '\0')
			s++;
	}
	return (res);
}
