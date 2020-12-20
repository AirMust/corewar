/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:46:24 by antondob          #+#    #+#             */
/*   Updated: 2020/12/20 03:22:30 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

unsigned int reverse_bytes(unsigned int num)
{
	num = (num & 0xFFFF0000) >> 16 | (num & 0x0000FFFF) << 16;
	num = (num & 0xFF00FF00) >> 8 | (num & 0x00FF00FF) << 8;
	return (num);
}

int get_byte_int(t_vm *vm, int position, int size_reg)
{
	int32_t		result;
	int32_t		current;
	char			sign;
	char			i;

	result = 0;
	i = 0;
	sign = ((STAGE[mod_position(position)] & MASK_SIGIN) == 0) ? 0 : 1;
	while (size_reg)
	{
		current = STAGE[mod_position(position + (size_reg--) - 1)];
		current = sign == 1 ? (current ^ 0xFF) : current;
		result += current << (i++ * 8);
	}
	result = (sign == 1) ? ~(result) : result;
	return result;
}
