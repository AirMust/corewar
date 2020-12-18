/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:37:02 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/19 02:54:48 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void get_op_code(t_vm *vm, t_process *proc)
{
	int code_id;

	code_id = get_byte_int(vm, PROC_POS, OP_CODE_LEN);
	proc->id_op = code_id;
	if (code_id >= 1 && code_id <= OP_N_FUN)
		proc->cycle_op = g_op[code_id - 1].cycles;
}

void get_op_type_agrs(t_vm *vm, t_process *proc, t_op *op)
{
	int type_args;
	if (op->is_type_args)
	{
		type_args = get_byte_int(vm, PROC_POS + OP_CODE_LEN, ARGS_CODE_LEN);
		if (op->args_num >= 1)
			proc->type_args[0] = g_type_args[((type_args & MASK_R) >> 6) - 1];
		if (op->args_num >= 2)
			proc->type_args[1] = g_type_args[((type_args & MASK_G) >> 4) - 1];
		if (op->args_num >= 3)
			proc->type_args[2] = g_type_args[((type_args & MASK_B) >> 2) - 1];
		return ;
	}
	proc->type_args[0] = op->type_args[0];
}

int		gap_op_args(t_process *proc, t_op *op)
{
	int	step;
	int	i;

	i = 0;
	step = OP_CODE_LEN + (op->is_type_args ? ARGS_CODE_LEN : 0);
	while (++i < op->args_num)
	{
		step += (proc->type_args[i] == T_REG ?
			REG_LEN : proc->type_args[i] == T_DIR ?
				op->t_dir_size : IND_SIZE);
	}
	return (step);
}

int		get_op_args(t_vm *vm, t_process *proc, int index_arg, int is_mod)
{
	t_op	*op;
	int		value;
	int		addr;

	op = &g_op[proc->id_op - 1];
	value = 0;
	if (proc->type_args[index_arg - 1] & T_REG)
		value =
}
