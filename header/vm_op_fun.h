/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:24:44 by airat_must        #+#    #+#             */
/*   Updated: 2020/12/18 16:45:11 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OP_FUN_H
# define OP_FUN_H

#include "vm.h"

# define OP_CODE	op->code
# define OP_N_ARG	op->code
# define OP_IS_TYPE	op->is_type_args

# define OP_N_FUN	16

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int			is_type_args;
	uint8_t		type_args[3];
	uint8_t		modify_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
	// void		(*func)(t_vm *, t_cursor *);

}				t_op;



static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.is_type_args = 0,
		.type_args = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 10,
		// .func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.is_type_args = 1,
		.type_args = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 5,
		// .func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.is_type_args = 1,
		.type_args = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 5,
		// .func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		// .func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		// .func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		// .func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		// .func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		// .func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.is_type_args = 0,
		.type_args = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 20,
		// .func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		// .func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		// .func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.is_type_args = 0,
		.type_args = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 800,
		// .func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.is_type_args = 1,
		.type_args = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		// .func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.is_type_args = 1,
		.type_args = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.t_dir_size = 2,
		.cycles = 50,
		// .func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.is_type_args = 0,
		.type_args = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 1000,
		// .func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.is_type_args = 1,
		.type_args = {T_REG, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 2,
		// .func = &op_aff
	}
};

#endif
