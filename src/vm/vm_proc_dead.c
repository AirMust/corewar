/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_proc_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:22:16 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 05:43:19 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

int			proc_is_dead(t_vm *vm, t_process *proc)
{
	return (vm->n_loop_dead <= 0 || vm->n_loop - proc->cycle_live >= vm->n_loop_dead);
}

void		proc_dead(t_vm *vm)
{
	t_process	*proc;
	t_process	*prev;
	t_process	*del;

	prev = NULL;
	proc = PROC;
	while (proc)
	{
		if(proc_is_dead(vm, proc) == 1 && vm->proc_num--)
		{
			del = proc;
			proc = proc->next;
			if (PROC == del)
				PROC = proc;
			if (prev)
				prev->next = proc;
			ft_memdel((void**)&del);
		}
		else
		{
			prev = proc;
			proc = proc->next;
		}

	}
}

void		vm_proc_dead(t_vm *vm)
{
	proc_dead(vm);
	vm->count_check++;
	if(vm->count_check == MAX_CHECKS || vm->count_live >= NBR_LIVE)
	{
		vm->n_loop_dead -= CYCLE_DELTA;
		vm->count_check = 0;
	}
	vm->count_live = 0;
	vm->n_loop_check = 0;
}
