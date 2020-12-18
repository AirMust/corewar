/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:00:53 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/15 00:49:30 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void	stage_free(void **stage)
{
	if (!*stage)
		return ;
	free(*stage);
	*stage = NULL;
}

void	players_free(t_player **players)
{
	if (!*players)
		return ;
	free(*players);
	*players = NULL;
}

void	process_free(t_process **process)
{
	t_process *tmp;

	if (!*process)
		return ;
	while (*process)
	{
		tmp = *process;
		*process = (*process)->next;
		free(tmp);
	}
}

void vm_free(t_vm **vm)
{
	if (!*vm)
		return ;
	stage_free(&((*vm)->stage));
	players_free(&((*vm)->players));
	process_free(&((*vm)->processes));
	free(*vm);
	*vm = NULL;
}
