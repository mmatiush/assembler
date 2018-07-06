/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:22:33 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/15 00:22:35 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp_haystack;
	const char	*tmp_needle;

	tmp_needle = needle;
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (len < ft_strlen(needle))
			return (NULL);
		tmp_haystack = haystack;
		while ((*tmp_haystack == *tmp_needle || *tmp_needle == '\0'))
		{
			if (*tmp_needle == '\0')
				return ((char*)haystack);
			tmp_needle++;
			tmp_haystack++;
		}
		len--;
		tmp_needle = needle;
		haystack++;
	}
	return (NULL);
}
