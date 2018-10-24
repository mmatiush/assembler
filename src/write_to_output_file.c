/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_output_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:40:24 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/24 21:03:41 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include <fcntl.h>

void		write_header_to_utput_file(t_header *header, int fd)
{
	size_t 	size;

	size = sizeof(t_header);
	write(fd, header, size);
}

char		*modify_file_name_ext(char *f_name)
{
	char	*cor_name;

	cor_name = ft_strchr(f_name ,'.');
	*cor_name = '\0';
	if (!(cor_name = ft_strjoin(f_name, ".cor")))
		exit(print_error(4));
	ft_printf("\n\n%s\n\n", cor_name);
	return (cor_name);
}

void		write_to_output_file(t_asm *a, char *f_name)
{
	char	*name;
	int		fd;

	name = modify_file_name_ext(f_name);
	if ((fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0711)) == -1)
		exit(print_error(11));

	write_header_to_utput_file(a->header, fd);
	free(name);

	close(fd);
}
