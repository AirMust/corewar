/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_preparation_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:53 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void	sort_players(t_vm *vm)
{
	int			i;
	int			j;
	t_player	tmp;

	i = -1;
	while (++i < N_PLAYERS)
	{
		j = i;
		while (++j < N_PLAYERS)
		{
			if (PLAYER[i].n_num > PLAYER[j].n_num)
			{
				tmp = PLAYER[i];
				PLAYER[i] = PLAYER[j];
				PLAYER[j] = tmp;
			}
		}
	}
}

void	prep_presentation(t_vm *vm)
{
	int i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (++i <= N_PLAYERS)
	{
		ft_printf("Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			PLAYER[i - 1].n_num, PLAYER[i - 1].exec_size,
				PLAYER[i - 1].name, PLAYER[i - 1].comment);
	}
}
