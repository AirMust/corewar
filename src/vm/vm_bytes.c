/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:46:24 by antondob          #+#    #+#             */
/*   Updated: 2020/12/18 17:03:51 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

unsigned int reverse_bytes(unsigned int num)
{
	num = (num & 0xFFFF0000) >> 16 | (num & 0x0000FFFF) << 16;
	num = (num & 0xFF00FF00) >> 8 | (num & 0x00FF00FF) << 8;
	return (num);
}

unsigned int get_byte_int(t_vm *vm, int position, int size_reg)
{
	int i;
	int x;
	i = -1;
	x = 0;
	while (++i < size_reg)
	{
		x = x << 8 | *(unsigned char *)(STAGE + mod_position(position + i));
	}
	return x;
}
