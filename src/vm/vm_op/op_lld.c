/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 04:08:09 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void		op_lld(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg_id;

	proc->step += ARGS_CODE_LEN;
	value = get_op_args(vm, proc, 1, 0);
	proc->carry = (value == 0 ? 1 : 0);
	reg_id = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	proc->step += REG_LEN;
	proc->reg[reg_id - 1] = value;
}
