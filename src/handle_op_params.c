/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:01:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/10/20 19:39:34 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

void	handle_op_param(t_asm *a, char *op_name, size_t param_index)
{
	if (!a->list)
	{
		free(op_name);
		param_index = 1;
	}
}
