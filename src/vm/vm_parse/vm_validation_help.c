/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:27:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

char	**valid_filename(t_vm *vm, char **input, int *i, int *count)
{
	if (*i == MAX_PLAYERS - 1)
		vm_error(2);
	PLAYER[++(*i)].file = ft_strdup(*input);
	*count = (*count > 0 ? *count - 1 : *count);
	return (input);
}

char	**valid_flags(t_vm *vm, char **input, int *i, int *count)
{
	if (!ft_strcmp(*input, "-n") && ft_is_number(*(input + 1)) &&
		(*i) < MAX_PLAYERS - 1 && !(*count) && *(input + 2))
	{
		PLAYER[(*i) + 1].n_on = 1;
		PLAYER[(*i) + 1].n_num = ft_atoi(*(++input));
		(*count)++;
	}
	else if (!ft_strcmp(*input, "-dump") && ft_is_number(*(input + 1)))
		DUMP = ft_atoi(*(++input));
	else if (!ft_strcmp(*input, "-v"))
		VIS = 1;
	else
		vm_error(1);
	return (input);
}
