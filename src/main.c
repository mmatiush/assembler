/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:34:19 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/09 18:03:22 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static int	check_argument_extension(const char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len < 3 || name[len - 1] != 's' || name[len - 2] != '.')
		return (1);
	return (0);
}

int			main(int ac, char *av[])
{
	if (ac != 2)
		return (print_error(0));
	if (check_argument_extension(av[1]))
		return (print_error(1));
	assembler(av[1]);
	system("leaks --quiet asm");
	return (0);
}
