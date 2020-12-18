/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:12:38 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/18 17:01:16 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int		mod_position(int position)
{
	position %= MEM_SIZE;
	position += (position < 0) ? MEM_SIZE : 0;
	return (position);
}

// int		get_size_op(t_process *current, t_op *op)
// {
// 	int	i;
// 	int	step;

// 	i = -1;
// 	step = OP_CODE_LEN + OP_IS_TYPE;
// 	while(++i < g_op[OP_CODE - 1].args_num)
// 	{
// 		step += get_size_op_arg(current-> op)
// 	}
// }
