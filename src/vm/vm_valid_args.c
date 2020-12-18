/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:42:44 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/18 19:45:35 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int valid_type_args(t_process *proc, t_op *op)
{
	int i;

	i = -1;
	while (++i < op->args_num)
		if (!(proc->type_args[i] & op->type_args[i]))
			return (0);
	return (1);
}

int valid_reg_args(t_vm *vm, t_process *proc, int step)
{
	int value;

	value = get_byte_int(vm, PROC_POS + step, T_REG);
	return (value > 0 && value <= REG_NUMBER);
}

int wm_valid_args(t_vm *vm, t_process *proc, t_op *op)
{
	int step;
	int i;

	if (!valid_type_args(proc, op))
		return (0);
	i = -1;
	step = OP_CODE_LEN + (op->is_type_args ? ARGS_CODE_LEN : 0);
	while (++i < op->args_num)
	{
		if (proc->type_args[i] == T_REG && !valid_reg_args(vm, proc, step))
			return (0);
		step += (proc->type_args[i] == T_REG ? REG_LEN : proc->type_args[i] == T_DIR ? op->t_dir_size : IND_SIZE);
	}
	PROC_STEP = step;
	return (1);
}
