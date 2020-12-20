/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/12/20 06:09:01 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

#define B_S 100

#include "../libft/header/libft.h"
#include "op.h"
#include "vm_struct.h"
#include "vm_op.h"

#include <fcntl.h>

#define OP_CODE_LEN 1
#define ARGS_CODE_LEN 1
#define REG_LEN 1

#define MASK_R 0b11000000 // Aka 0xCO
#define MASK_G 0b00110000 // Aka 0x30
#define MASK_B 0b00001100 // Aka 0xC
#define MASK_A 0b00000011 // Aka 0x3
#define MASK_SIGIN 0b10000000

static unsigned char g_type_args[3] = {
	T_REG,
	T_DIR,
	T_IND};
/*
** Virtual machine funcs
*/

/*
** Memory
*/

t_vm *vm_create(void);
void vm_free(t_vm **vm);
unsigned reverse_bytes(unsigned num);
/*
** Validation, preparation, presentation
*/

void vm_valid(t_vm *vm, char **input);
char **valid_flags(t_vm *vm, char **input, int *i, int *count);
char **valid_filename(t_vm *vm, char **input, int *j, int *count);
void vm_prep(t_vm *vm);
void prep_presentation(t_vm *vm);
void sort_players(t_vm *vm);

t_process *proc_init(int id_player, int addr);
void proc_insert(t_process **l_proc, t_process *proc);
t_process *proc_copy(t_process *proc, int addr);
int get_byte_int(t_vm *vm, int position, int size_reg);
void vm_war(t_vm *vm);
void get_op_code(t_vm *vm, t_process *proc);
void vm_print_proc(t_process *proc);
int mod_position(int position);
void get_op_type_agrs(t_vm *vm, t_process *proc, t_op *op);
int wm_valid_args(t_vm *vm, t_process *proc, t_op *op);
int gap_op_args(t_process *proc, t_op *op);
void proc_step(t_process *proc);
int get_op_args(t_vm *vm, t_process *proc, int index_arg, int is_mod);
int get_step(int type_arg, t_op *op);
void put_int_byte(t_vm *vm, int32_t addr, int32_t value,
				  int32_t size);
void vm_proc_dead(t_vm *vm);
void	print_last_alive(t_vm *vm);
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

void vm_error(int error_code);

#endif
