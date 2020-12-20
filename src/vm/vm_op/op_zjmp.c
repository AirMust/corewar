/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 04:07:32 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void		op_zjmp(t_vm *vm, t_process *proc)
{
	int		addr;

	addr = get_op_args(vm, proc, 1, 1);
	if (proc->carry)
	{
		PROC_POS = mod_position(PROC_POS + (addr % IDX_MOD));
		PROC_STEP = 0;
	}
}

// ft_printf("add: %d %d %d %d %d %d %d\n", value, reg_1, reg_2, reg_3, PROC_REG[reg_3 - 1], PROC_POS, PROC_STEP);
