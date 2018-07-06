/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:00:15 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/14 22:05:26 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp_haystack;
	const char	*tmp_needle;

	tmp_needle = needle;
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		tmp_haystack = haystack;
		while (*tmp_haystack == *tmp_needle || *tmp_needle == '\0')
		{
			if (!(*tmp_needle))
				return ((char*)haystack);
			tmp_needle++;
			tmp_haystack++;
		}
		tmp_needle = needle;
		haystack++;
	}
	return (NULL);
}
