/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:17:51 by mmatiush          #+#    #+#             */
/*   Updated: 2017/12/05 12:17:52 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *root;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	if (!(root = f(lst)))
		return (NULL);
	lst = lst->next;
	temp = root;
	while (lst)
	{
		if (!(temp->next = f(lst)))
			return (NULL);
		temp = temp->next;
		lst = lst->next;
	}
	return (root);
}
