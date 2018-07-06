/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischrctr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:29:04 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/23 13:29:05 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function checks if a given int is a printing character (except space).
** Returns 1 if true, and 0 in any other case.
*/

int		ft_ischrctr(int c)
{
	if (c > ' ' && c <= '~')
		return (1);
	else
		return (0);
}
