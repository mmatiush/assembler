/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ushort_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:28:32 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:05:19 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short	ft_swap_ushort_bytes(unsigned short n)
{
	unsigned short res;

	res = (n >> 8) | (n << 8);
	return (res);
}
