/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:02:14 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:06:33 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*tmp;
	size_t	s_len;

	if (s == NULL || s[0] == '\0' || len == 0)
		return (NULL);
	s_len = (ft_strlen(s) < len) ? ft_strlen(s) : len;
	tmp = (char*)malloc(sizeof(char) * (s_len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strncpy(tmp, s, s_len);
	tmp[s_len] = '\0';
	return (tmp);
}
