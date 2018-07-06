/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:11:17 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/18 21:11:18 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;
	char	*source;

	source = (char*)s;
	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (source[i])
	{
		str[i] = f(source[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
