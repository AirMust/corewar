/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:00:13 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/05 00:55:59 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

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
