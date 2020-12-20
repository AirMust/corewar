/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:00:13 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/20 06:36:19 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

t_vm	*vm_create(void)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		vm_error(3);
	if (!(PLAYER = ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
		vm_error(3);
	DUMP = -1;
	vm->n_loop_dead = CYCLE_TO_DIE;
	vm->n_loop_check = 0;
	vm->count_check = 0;
	vm->count_live = 0;
	return (vm);
}
