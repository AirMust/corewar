/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 04:06:12 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void			op_lfork(t_vm *vm, t_process *proc)
{
	int			addr;
	t_process	*new;

	addr = get_op_args(vm, proc, 1, 1);
	new = proc_copy(proc, addr);
	proc_insert(&(vm->processes), new);
	vm->proc_num++;
}
