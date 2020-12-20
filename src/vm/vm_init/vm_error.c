/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:14:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/20 06:27:38 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

char 		g_error[100][100]={
		"ERROR: no error",
		"USAGE: ",
		"ERROR: number of players exceeds MAX_PLAYERS",
		"ERROR: not enough memory to allocate",
		"ERROR: wrong file extension",
		"ERROR: cannot open file",
		"ERROR: cannot close file",
		"ERROR: file is empty",
		"ERROR: wrong binary encoding",
		"ERROR: execution code size doesn't match header",
		"ERROR: execution code exceeds CHAMP_MAX_SIZE",
		"ERROR: invalid flag"
	};

void	vm_error(int error_code)
{
	ft_printf("%s\n", g_error[error_code]);
	exit(error_code);
}
