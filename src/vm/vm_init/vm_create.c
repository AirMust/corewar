/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:00:13 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/19 02:40:40 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/vm.h"

t_vm	*vm_create(void)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		vm_error(3);
	if (!(STAGE = ft_memalloc(MEM_SIZE)))
		vm_error(3);
	if (!(PLAYER = ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
		vm_error(3);
	DUMP = -1;
	return (vm);
}
