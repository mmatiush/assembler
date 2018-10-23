/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:38:39 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/23 15:31:56 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of digits in int.
*/

size_t		ft_intlen(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
