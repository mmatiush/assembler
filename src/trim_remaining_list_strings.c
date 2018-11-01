/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_remaining_list_strings.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:00:46 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:09:54 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void	trim_remaining_list_strings(t_data *list)
{
	while (list)
	{
		list->data = ft_strtrim_free(list->data);
		list = list->next;
	}
}
