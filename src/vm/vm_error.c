/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:14:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/09 16:51:39 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

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
