/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:12:38 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 01:00:00 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int		mod_position(int position)
{
	position %= MEM_SIZE;
	position += (position < 0) ? MEM_SIZE : 0;
	return (position);
}

int		get_step(int type_arg, t_op *op)
{
	if (type_arg & T_REG)
		return (REG_LEN);
	else if (type_arg & T_DIR)
		return (op->t_dir_size);
	else if (type_arg & T_IND)
		return (IND_SIZE);
	return (0);
}

void		int32_to_bytecode(t_vm *vm, int32_t addr, int32_t value,
						int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		vm->stage[mod_position(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}
