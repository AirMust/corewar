/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_st(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg;
	int		addr;

	PROC_STEP += ARGS_CODE_LEN;
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	if (PROC_TA[1] == T_REG)
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
		PROC_STEP += REG_LEN;
		PROC_REG[addr - 1] = value;
	}
	else
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, IND_SIZE);
		PROC_STEP += IND_SIZE;
		put_int_byte(vm, PROC_POS + (addr % IDX_MOD),
							value, DIR_SIZE);
	}
}
