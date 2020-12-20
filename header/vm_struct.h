/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:18:40 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/20 01:38:34 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCT_H
# define VM_STRUCT_H

#include "vm.h"


# define STAGE		vm->stage
# define PLAYER		vm->players
# define PROC		vm->processes
# define DUMP		vm->dump
# define N_PLAYERS	vm->players_num
# define VIS		vm->visualizer

# define PROC_POS	proc->curr_position
# define PROC_STEP	proc->step
# define PROC_REG	proc->reg
# define PROC_TA	proc->type_args
/*
** list of players
*/

typedef struct			s_player
{
	char				*file;							// file name of the player
	int					n_on;							// flag "n" on/off
	int					n_num;							// number with the flag "n"
	int					fd;								// file descriptor
	size_t				exec_size; 						//	size of execution code from header
	char				name[PROG_NAME_LENGTH + 1];		// name of the player form header
	char				comment[COMMENT_LENGTH + 1];	// player comment
	void				*exec_code;
	int					loop_live;
}						t_player;

/*
** list of processes
*/


typedef struct			s_process
{
	int					id;							// id коретки
	int					carry;						// Спец флаг
	int					id_op;						// Код операции
	int					cycle_op; 					// Количество циклов до исполнения
	int					cycle_live;					// Крайний цикл когда чемпоин еще был жив
	int					curr_position;				// Текущая позиция на арене
	size_t				step;						// Через сколько байтов нужно перепрыгнуть
	int					reg[REG_NUMBER];			//
	int					id_player;					//
	uint32_t			type_args[3];				// Текущие аргументы конструкции op
	struct s_process	*next;						// Следущая каретка
}						t_process;
/*
** main structure for virtual machine
*/

/**
 *
 */
typedef	struct	s_vm
{
	uint8_t		stage[MEM_SIZE];			//арена
	t_player	*players;		//игроки
	t_process	*processes;		//процессы
	int			dump; 			//флаг dump. Если флаг установлен, то dump = числу идущему после флага. Дефолт = -1
	int			visualizer;
	int			players_num;	//количество игроков
	int			proc_num;		//Количество кареток
	int			n_loop;			//Количество циклов
	int			n_loop_check;	//Количество циклов до проверки

}				t_vm;

/*
** structure for file
*/

typedef struct	s_file
{
	size_t		size;
	char		*raw;
}				t_file;

#endif
