/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:53 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/19 02:40:14 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

static void numerate_players(t_vm *vm, int *index)
{
	int i;
	int j;

	i = -1;
	while (++i < N_PLAYERS)
	{
		if (PLAYER[i].n_num)
			continue;
		j = -1;
		while (++j < N_PLAYERS && index[j])
			;
		PLAYER[i].n_num = j + 1;
		index[j]++;
	}
}

static void prep_players(t_vm *vm)
{
	int *index;
	int i;

	i = -1;
	index = ft_memalloc(N_PLAYERS * 4);
	while (++i < N_PLAYERS)
	{
		if (PLAYER[i].n_on && PLAYER[i].n_num > 0 &&
			PLAYER[i].n_num <= N_PLAYERS &&
			index[PLAYER[i].n_num - 1] == 0)
			index[PLAYER[i].n_num - 1]++;
		else
			PLAYER[i].n_num = 0;
	}
	numerate_players(vm, index);
	sort_players(vm);
	free(index);
}

static void prep_stage(t_vm *vm)
{
	int delta;
	int i;

	delta = MEM_SIZE / N_PLAYERS;
	i = -1;
	while (++i < N_PLAYERS)
		ft_memcpy(STAGE + delta * i,
				  PLAYER[i].exec_code, PLAYER[i].exec_size);
}

static void prep_proc(t_vm *vm)
{
	t_process *new;
	t_process *tmp;
	int i;

	i = -1;
	while (++i < N_PLAYERS)
	{
		if (!(new = ft_memalloc(sizeof(t_process))))
			vm_error(3);
		new->id = i + 1;
		new->curr_position =
			MEM_SIZE / N_PLAYERS *(i);
		new->reg[0] = -(i + 1);
		tmp = PROC;
		PROC = new;
		new->next = tmp;
	}
	vm->proc_num = N_PLAYERS;
}

void vm_prep(t_vm *vm)
{
	prep_players(vm);
	prep_stage(vm);
	prep_proc(vm);
	prep_presentation(vm);
}
