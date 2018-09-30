/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:58:07 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/21 16:58:08 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrimlen(const char *s)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		res++;
	}
	if (s[i] == '\0')
		return (ft_strlen(s));
	i = (ft_strlen(s) - 1);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		res++;
	}
	return (res);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	res_strlen;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	res_strlen = (ft_strlen(s) - ft_strtrimlen(s));
	if (!(str = (char*)malloc(sizeof(*str) * (res_strlen + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < res_strlen)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char			*ft_strtrim_free(char *str)
{
	char	*temp;

	if (!str)
		return (str);
	temp = ft_strtrim(str);
	free(str);
	return (temp);
}
