/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:30:07 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/18 16:35:58 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void vm_print_proc(t_process *proc)
{
	ft_printf("\n ------ Метасведения каретки ------ \n");
	ft_printf("Идентификатор\t\t\t| %d\n", proc->id);
	ft_printf("Код операции\t\t\t| %d\n", proc->id_op);
	ft_printf("Кол. циклов до OP\t\t| %d\n", proc->cycle_op);
	ft_printf("Текущая позиция относительная\t| %d\n", proc->curr_position);
}
