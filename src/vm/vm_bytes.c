/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:46:24 by antondob          #+#    #+#             */
/*   Updated: 2020/12/20 06:50:18 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"

unsigned int	reverse_bytes(unsigned int num)
{
	num = (num & 0xFFFF0000) >> 16 | (num & 0x0000FFFF) << 16;
	num = (num & 0xFF00FF00) >> 8 | (num & 0x00FF00FF) << 8;
	return (num);
}

int				get_byte_int(t_vm *vm, int position, int size_reg)
{
	int32_t		result;
	int32_t		current;
	char		sign;
	char		i;

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
	return (result);
}

void			put_int_byte(t_vm *vm, int addr, int value, int size_reg)
{
	int8_t		i;

	i = 0;
	while (size_reg)
	{
		STAGE[mod_position(addr + size_reg - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size_reg--;
	}
}
