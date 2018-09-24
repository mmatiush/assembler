/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:31:45 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/22 19:31:47 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**freeing(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static size_t		wdnum(char const *s, char c)
{
	size_t	res;
	size_t	i;
	int		sym;

	res = 0;
	sym = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			sym = 1;
			i++;
		}
		res += (sym == 1) ? 1 : 0;
		sym = 0;
		if (s[i])
			i++;
	}
	return (res);
}

static size_t		wdlen(char const *s, size_t i, char c)
{
	size_t	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (wdnum(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if (!(str[j] = (char*)malloc(sizeof(char) * (wdlen(s, i, c) + 1))))
				return (str = freeing(str));
			while (s[i] && s[i] != c)
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
		}
	}
	str[j] = NULL;
	return (str);
}
