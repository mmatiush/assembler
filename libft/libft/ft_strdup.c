/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:48:37 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/03 16:48:39 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(*tmp) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, s);
	return (tmp);
}
