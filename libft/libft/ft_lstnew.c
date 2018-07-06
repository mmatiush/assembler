/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:56:55 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/29 18:56:58 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if (!(res = (t_list*)malloc(sizeof(*res))))
		return (NULL);
	if (content)
	{
		res->content_size = content_size;
		if (!(res->content = malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		ft_memcpy(res->content, content, content_size);
	}
	else
	{
		res->content_size = 0;
		res->content = NULL;
	}
	res->next = NULL;
	return (res);
}
