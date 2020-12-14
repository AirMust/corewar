/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/12/14 23:36:16 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define B_S		100
# define STAGE		vm->stage
# define PLAYER		vm->players
# define PROC		vm->processes
# define DUMP		vm->dump
# define N_PLAYERS	vm->players_num
# define VIS		vm->visualizer

# include "../libft/header/libft.h"
# include "op.h"
# include "op_fun.h"
# include <fcntl.h>

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
}						t_player;

/*
** list of processes
*/

typedef struct			s_process
{
	int					id;
	int					carry;
	int					curr_op;
	int					cycle_op;
	int					cycle_live;
	void				*curr_position;
	size_t				step;
	int					reg[REG_NUMBER];
	struct s_process	*next;
}						t_process;
/*
** main structure for virtual machine
*/

typedef	struct	s_vm
{
	void		*stage;			//арена
	t_player	*players;		//игроки
	t_process	*processes;		//процессы
	int			dump; 			//флаг dump. Если флаг установлен, то dump = числу идущему после флага. Дефолт = -1
	int			visualizer;
	int			players_num;	//количество игроков
}				t_vm;

/*
** structure for file
*/

typedef struct	s_file
{
	size_t		size;
	char		*raw;
}				t_file;

/*
** Virtual machine funcs
*/

/*
** Memory
*/

t_vm		*vm_create(void);
void		vm_free(t_vm **vm);
unsigned	reverse_bytes(unsigned num);

/*
** Validation, preparation, presentation
*/

void		vm_valid(t_vm *vm, char **input);
char		**valid_flags(t_vm *vm, char **input, int *i, int *count);
char		**valid_filename(t_vm *vm, char **input, int *j, int *count);
void		vm_prep(t_vm *vm);
void		prep_presentation(t_vm *vm);
void		sort_players(t_vm *vm);

/*
** Error management
*/

/*
** Virtual Machine ERROR CODES
** 0 - default
** 1 - no arguments, usage;
** 2 - number of players exceeds MAX_PLAYERS;
** 3 - allocation error
** 4 - wrong file extension
** 5 - cannot open file
** 6 - cannot close file
** 7 - file is empty
** 8 - wrong binary encoding (magic header)
** 9 - execution code is corrupted (wrong size)
** 10 - execution code exceeds CHAMP_MAX_SIZE
*/

void		vm_error(int error_code);

#endif
