/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:27:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/12/15 00:49:43 by airat_must       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void	read_file(t_file *file, int fd)
{
	int		ret;
	char	buff[B_S + 1];
	char	*tmp;
	int		i;

	tmp = NULL;
	while ((ret = read(fd, buff, B_S)))
	{
		tmp = ft_memalloc(file->size + ret);
		i = -1;
		while (++i < (int)file->size)
			tmp[i] = file->raw[i];
		i = -1;
		while (++i < ret)
			tmp[i + file->size] = buff[i];
		free(file->raw);
		file->raw = tmp;
		file->size += ret;
	}
}

static void	valid_champ(t_vm *vm, int i)
{
	t_file	file;
	void	*curr;

	file.size = 0;
	file.raw = NULL;
	read_file(&file, PLAYER[i].fd); 												//читаем файл
	if (!file.size)																	//проверка пустой ли файл
		vm_error(7);
	///*****test*****/	ft_printf("file size = %d\n", file.size);
	curr = file.raw;
	if (reverse_bytes(*(unsigned*)curr) ^ COREWAR_EXEC_MAGIC) 						// магическое число
		vm_error(8);
	ft_printf("%с\n", *(unsigned*)curr);
	curr += 4;
	ft_memcpy(PLAYER[i].name, curr, (size_t)PROG_NAME_LENGTH + 1);					// читаем имя
	///*****test*****/	ft_printf("player name = %s\n", PLAYER[i].name);
	ft_printf("%с\n", *(unsigned*)curr);
	curr += PROG_NAME_LENGTH + 1 + 4 - (PROG_NAME_LENGTH + 1) % 4;
	PLAYER[i].exec_size = reverse_bytes(*(unsigned*)curr);
	ft_printf("%с\n", *(unsigned*)curr);

	///*****test*****/	ft_printf("player size = %d\n", PLAYER[i].exec_size);		// размер исполняемого года в хедере
	curr += 4;
	ft_memcpy(PLAYER[i].comment, curr, (size_t)COMMENT_LENGTH + 1);					// читаем комментарий
	///*****test*****/	ft_printf("player comment = %s\n", PLAYER[i].comment);
	curr += COMMENT_LENGTH + 1 + 4 - (COMMENT_LENGTH + 1) % 4;
	file.size -= sizeof(header_t);													// считаем количество байт исполняемого кода
	if (PLAYER[i].exec_size != file.size)											// проверяем совпадение реального размера кода и указанного в хедере
		vm_error(9);
	if (PLAYER[i].exec_size > CHAMP_MAX_SIZE)										// проверяем что размер кода чемпиона не превышает реальный размер
		vm_error(10);
	///*****test*****/	ft_printf("real player size = %d\n", file.size);
	if (!(PLAYER[i].exec_code = ft_memalloc(file.size)))							// выделяем память под код игрока
		vm_error(3);
	ft_memcpy(PLAYER[i].exec_code, curr, file.size);								// копируем исполняемый код
}

static void	valid_files(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < N_PLAYERS)
	{
		PLAYER[i].fd = open(PLAYER[i].file, O_RDONLY);
		if (PLAYER[i].fd < 0)
			vm_error(5);
		valid_champ(vm, i);
		if (close(PLAYER[i].fd) < 0)
			vm_error(6);
	}
}

static void	valid_args(t_vm *vm, char **input)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while ((*input) && *(++input))
	{
		if (**input == '-')
			input = valid_flags(vm, input, &i, &count);
		else if (ft_strstr(*input, ".cor"))
			input = valid_filename(vm, input, &i, &count);
		else
			vm_error(4);
	}
	N_PLAYERS = i + 1;
}

void		vm_valid(t_vm *vm, char **input)
{
	valid_args(vm, input);
	valid_files(vm);
}
