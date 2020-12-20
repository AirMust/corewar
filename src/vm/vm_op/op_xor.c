/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 03:27:41 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void	op_xor(t_vm *vm, t_process *proc)
{
	int			value_1;
	int			value_2;
	int			value;
	int			reg;

	PROC_STEP += (OP_CODE_LEN + ARGS_CODE_LEN);
	value_1 = get_op_args(vm, proc, 1, 1);
	value_2 = get_op_args(vm, proc, 2, 1);
	value = value_1 ^ value_2;
	proc->carry = (value == 0 ? 1 : 0);
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	PROC_REG[reg - 1] = value;
	// ft_printf("add: %d %d %d %d %d %d %d\n", value, reg_1, reg_2, reg_3, PROC_REG[reg_3 - 1], PROC_POS, PROC_STEP);
}
