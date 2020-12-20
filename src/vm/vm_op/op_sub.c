/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_sub(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg_1;
	int		reg_2;
	int		reg_3;

	PROC_STEP += ARGS_CODE_LEN;
	reg_1 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	reg_2 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	reg_3 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg_1 - 1] - PROC_REG[reg_2 - 1];
	proc->carry = (value == 0 ? 1 : 0);
	PROC_REG[reg_3 - 1] = value;
	// ft_printf("add: %d %d %d %d %d %d %d\n", value, reg_1, reg_2, reg_3, PROC_REG[reg_3 - 1], PROC_POS, PROC_STEP);
}
