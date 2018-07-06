/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:45:29 by mmatiush          #+#    #+#             */
/*   Updated: 2017/11/18 22:45:31 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisint(char *str)
{
	char	*temp;

	if (!str)
		return (0);
	if (ft_strequ(temp = ft_itoa((ft_atoi(str))), str))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}
