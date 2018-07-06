/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:29:10 by mmatiush          #+#    #+#             */
/*   Updated: 2017/12/04 17:29:12 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *node;

	if (!alst || !del)
		return ;
	node = *alst;
	while (node)
	{
		temp = node->next;
		del(node->content, node->content_size);
		free(node);
		node = temp;
	}
	*alst = NULL;
}
