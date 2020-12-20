/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_ldi(t_vm *vm, t_process *proc)
{
	int		reg;
	int		addr_1;
	int		addr_2;

	PROC_STEP += ARGS_CODE_LEN;
	addr_1 = get_op_args(vm, proc, 1, 1);
	addr_2 = get_op_args(vm, proc, 2, 1);
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	proc->reg[reg - 1] = get_byte_int(vm, PROC_POS + ((addr_1 + addr_2) % IDX_MOD), DIR_SIZE);
}
