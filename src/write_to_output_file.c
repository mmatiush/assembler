/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_output_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:40:24 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:23:03 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include <fcntl.h>

void		write_header_to_output_file(t_header *header, int fd)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	if (!ft_is_big_endian())
	{
		header->magic = ft_swap_uint_bytes(header->magic);
		header->prog_size = ft_swap_uint_bytes(header->prog_size);
	}
	ptr = (char *)header;
	size = sizeof(t_header);
	i = 0;
	while (i < size)
	{
		write(fd, ptr + i, 1);
		i++;
	}
}

char		*modify_file_name_ext(char *f_name)
{
	char	*cor_name;

	cor_name = ft_strrchr(f_name, '.');
	*cor_name = '\0';
	if (!(cor_name = ft_strjoin(f_name, ".cor")))
		exit(print_error(4));
	ft_printf("Writing output program to %s\n", cor_name);
	return (cor_name);
}

void		write_params_to_output_file(t_ops *op, int fd)
{
	int		i;
	void	*ptr;

	i = 0;
	while (op->param_size[i] && i < NEW_MAX_OP_ARGS_NUMBER)
	{
		ptr = &op->param[i];
		if (!ft_is_big_endian())
		{
			if (op->param_size[i] == 2)
				op->param[i] = ft_swap_ushort_bytes(op->param[i]);
			if (op->param_size[i] == 4)
				op->param[i] = ft_swap_uint_bytes(op->param[i]);
		}
		write(fd, ptr, op->param_size[i]);
		i++;
	}
}

void		write_instructions_to_output_file(t_labels *label, int fd)
{
	t_ops		*op;

	while (label)
	{
		op = label->ops;
		while (op)
		{
			write(fd, &op->op_ptr->op_code, OP_CODE_SIZE);
			if (op->codage)
				write(fd, &op->codage, CODAGE_SIZE);
			write_params_to_output_file(op, fd);
			op = op->next;
		}
		label = label->next;
	}
}

void		write_to_output_file(t_asm *a, char *f_name)
{
	char	*name;
	int		fd;

	name = modify_file_name_ext(f_name);
	if ((fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0711)) == -1)
		exit(print_error(11));
	write_header_to_output_file(a->header, fd);
	write_instructions_to_output_file(a->labels, fd);
	free(name);
	close(fd);
}
