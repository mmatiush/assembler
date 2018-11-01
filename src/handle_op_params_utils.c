/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_params_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <mmatiush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:47:07 by mmatiush          #+#    #+#             */
/*   Updated: 2018/11/01 19:35:34 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void			add_codage(t_asm *a, size_t reg, size_t param_index)
{
	if (param_index == 0)
		a->cur_op->codage += (reg << 6);
	else if (param_index == 1)
		a->cur_op->codage += (reg << 4);
	else if (param_index == 2)
		a->cur_op->codage += (reg << 2);
	else
		exit(-1);
}

bool			check_number_param(char *param)
{
	if (*param == '-' && ft_isdigit(*(param + 1)))
		param++;
	while (*param)
	{
		if (!ft_isdigit(*param))
			return (true);
		param++;
	}
	return (false);
}
