/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:49:18 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 03:52:48 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void	op_aff(t_vm *vm, t_process *proc)
{
	int		reg;
	int		value;

	PROC_STEP += OP_CODE_LEN + ARGS_CODE_LEN;
	reg = get_byte_int(vm, proc, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	if (vm->is_aff)
		ft_printf("Aff: %c\n", (char)value);
}
