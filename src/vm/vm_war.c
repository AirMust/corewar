/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_war.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:42:51 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 03:52:59 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void vm_run_op(t_vm *vm, t_process *proc)
{
	t_op *op;

	op = NULL;
	if (proc->cycle_op == 0)
		get_op_code(vm, proc);
	if (proc->cycle_op > 0)
		proc->cycle_op--;
	if (proc->cycle_op == 0)
	{
		if (proc->id_op >= 1 && proc->id_op <= OP_N_FUN)
			op = &g_op[proc->id_op - 1];
		if (op)
		{

			get_op_type_agrs(vm, proc, op);
			if (wm_valid_args(vm, proc, op))
			{
				ft_printf("VM %zd, ID: %d\tID_player: %d\tFUN: %s\tPOS: %d, %d %d\n", vm->n_loop, proc->id, proc->id_player, op->name, PROC_POS, proc->reg[0], proc->reg[1]);
				op->func(vm, proc);
			}
			else
				proc->step += gap_op_args(proc, op);
		}
		else
			proc->step = OP_CODE_LEN;
		proc_step(proc);
	}
	// ft_printf("-> %d, VM: %d, PROC: %d\n", PROC_POS, vm->n_loop, proc->cycle_op);
}
// vm_print_proc(proc);
// }
void vm_loop_war(t_vm *vm)
{
	t_process *cur_proc;

	vm->n_loop += 1;
	vm->n_loop_check += 1;
	cur_proc = PROC;
	while (cur_proc)
	{
		vm_run_op(vm, cur_proc);
		cur_proc = cur_proc->next;
	}
}

void vm_war(t_vm *vm)
{
	int i;

	i = 0;
	while (vm->proc_num && ++i < 4172)
	{
		vm_loop_war(vm);
	}
	// t_process *temp;
	// temp = vm->processes;
	// 	while(temp)
	// 	{
	// 		ft_printf("\n%2d -> %2d", temp->id, temp->id_player);
	// 		i = -1;
	// 		while(++i < 3)
	// 			ft_printf("%9d", temp->type_args[i]);
	// 		temp = temp->next;
	// 	}
	// 	ft_printf("\n");
	// 	i = -1;
	// 	while(++i < MEM_SIZE)
	// 	{
	// 		if(i % 30 == 0)
	// 			ft_printf("\n%d:\t", i / 30);
	// 		ft_printf("%3d ", vm->stage[i]);
	// 	}
}
