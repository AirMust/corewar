/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 01:01:58 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void op_st(t_vm *vm, t_process *proc)
{
	int value;
	int reg;
	int addr;

	PROC_STEP += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, 1);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	if (PROC_TA[1] == T_REG)
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, 1);
		PROC_REG[addr - 1] = value;
		PROC_STEP += REG_LEN;
	}
	else
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, IND_SIZE);
		int32_to_bytecode(vm, PROC_POS + (addr % IDX_MOD),
							value, DIR_SIZE);
		PROC_STEP += IND_SIZE;
		ft_printf("ID: %d, FUN: POS: %d, %d %d\n", proc->id, PROC_POS, proc->reg[0], proc->reg[1]);

		// ft_printf("----- %d ----", addr);
	}
}
