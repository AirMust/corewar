/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:17:37 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/19 04:58:29 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

void	op_live(t_vm *vm, t_process *proc)
{
	int			player_id;
	t_player	*player;

	player = NULL;
	proc->step += OP_CODE_LEN;
	player_id = get_op_args(vm, proc, 1, 0);
	proc->cycle_live = vm->n_loop;
	if (player_id < 0 && player_id >= -(vm->players_num))
	{
		player = &vm->players[-player_id - 1];
		player->loop_live = vm->n_loop;
	}
	// ft_printf("Live: %d %d\n", player_id, PROC_STEP);

}
