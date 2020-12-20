# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/12/20 05:37:13 by airat_must       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

FLAGS = -Wall  -Werror -Wextra
# -Wall -Werror -Wextra -O2

# /*
# ** ========================== HEADER ==============================
# */
INCS = vm.h
IDIR = header
LDIR = libft
INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))
INCLUDES = $(addprefix $(IDIR)/,$(INCS))

LIBFT = $(addprefix $(LDIR)/,libft.a)

# /*
# ** ====================== SOURCE LS MAIN ==========================
# */
SDIR = src
ODIR = obj

SRCS = corewar.c


SOURCES = $(addprefix $(SDIR)/,$(SRCS))
OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

# /*
# ** ====================== SOURCE VM ==========================
# */
SDIR_VM = src/vm
ODIR_VM = obj/vm

SRC_VM = vm_war.c
SRC_VM += vm_bytes.c
SRC_VM += vm_print.c
SRC_VM += vm_op.c
SRC_VM += vm_proc.c
SRC_VM += vm_valid_args.c
SRC_VM += vm_proc_dead.c
SRC_VM += utils.c


SOURCES_VM = $(addprefix $(SDIR_VM)/,$(SRC_VM))
OBJECTS_VM = $(addprefix $(ODIR_VM)/,$(SRC_VM:.c=.o))

# /*
# ** ====================== SOURCE VM_INIT ==========================
# */
SDIR_VM_INIT = src/vm/vm_init
ODIR_VM_INIT = obj/vm/vm_init

SRC_VM_INIT = vm_create.c
SRC_VM_INIT += vm_error.c
SRC_VM_INIT += vm_free.c


SOURCES_VM_INIT = $(addprefix $(SDIR_VM_INIT)/,$(SRC_VM_INIT))
OBJECTS_VM_INIT = $(addprefix $(ODIR_VM_INIT)/,$(SRC_VM_INIT:.c=.o))

# /*
# ** ====================== SOURCE VM_PARSE ==========================
# */
SDIR_VM_PARSE = src/vm/vm_parse
ODIR_VM_PARSE = obj/vm/vm_parse

SRC_VM_PARSE = vm_preparation.c
SRC_VM_PARSE += vm_preparation_help.c
SRC_VM_PARSE += vm_validation.c
SRC_VM_PARSE += vm_validation_help.c


SOURCES_VM_PARSE = $(addprefix $(SDIR_VM_PARSE)/,$(SRC_VM_PARSE))
OBJECTS_VM_PARSE = $(addprefix $(ODIR_VM_PARSE)/,$(SRC_VM_PARSE:.c=.o))


# /*
# ** ====================== SOURCE VM_OP ==========================
# */
SDIR_VM_OP = src/vm/vm_op
ODIR_VM_OP = obj/vm/vm_op

SRC_VM_OP = op_live.c
SRC_VM_OP += op_ld.c
SRC_VM_OP += op_st.c
SRC_VM_OP += op_add.c
SRC_VM_OP += op_sub.c
SRC_VM_OP += op_and.c
SRC_VM_OP += op_or.c
SRC_VM_OP += op_xor.c
SRC_VM_OP += op_zjmp.c
SRC_VM_OP += op_ldi.c
SRC_VM_OP += op_sti.c
SRC_VM_OP += op_fork.c
SRC_VM_OP += op_lld.c
SRC_VM_OP += op_lldi.c
SRC_VM_OP += op_lfork.c
SRC_VM_OP += op_aff.c




SOURCES_VM_OP = $(addprefix $(SDIR_VM_OP)/,$(SRC_VM_OP))
OBJECTS_VM_OP = $(addprefix $(ODIR_VM_OP)/,$(SRC_VM_OP:.c=.o))

.PHONY: clean fclean all re $(LIBFT)

all : $(NAME) Makefile
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) : $(LIBFT) $(OBJECTS) $(OBJECTS_VM) $(OBJECTS_VM_INIT) $(OBJECTS_VM_PARSE) $(OBJECTS_VM_OP) $(INCLUDES)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(OBJECTS_VM) $(OBJECTS_VM_INIT) $(OBJECTS_VM_PARSE) $(OBJECTS_VM_OP)  -I $(IDIR) $(LIBFT)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) : Makefile
	@make -C $(LDIR) 2> tmp.log

# /*
# ** =================== MAKE VM_OP ========================
# */
$(ODIR_VM_OP)/%.o : $(SDIR_VM_OP)/%.c $(INCLUDES)
	@if [[ $< == src/vm/vm_op/op_live.c ]]; then \
		echo "\n > Make \033[33mvm op\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM_OP) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** =================== MAKE VM_PARSE ========================
# */
$(ODIR_VM_PARSE)/%.o : $(SDIR_VM_PARSE)/%.c $(INCLUDES)
	@if [[ $< == src/vm/vm_parse/vm_preparation.c ]]; then \
		echo "\n > Make \033[33mvm parse\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM_PARSE) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** =================== MAKE VM_INIT ========================
# */
$(ODIR_VM_INIT)/%.o : $(SDIR_VM_INIT)/%.c $(INCLUDES)
	@if [[ $< == src/vm/vm_init/vm_create.c ]]; then \
		echo "\n > Make \033[33mvm init \033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM_INIT) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== MAKE VM ==========================
# */
$(ODIR_VM)/%.o : $(SDIR_VM)/%.c $(INCLUDES)
	@if [[ $< == src/vm/vm_war.c ]]; then \
		echo "\n > Make \033[33mvm\t\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== SOURCE MAIN  =======================
# */
$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@if [[ $< == src/corewar.c ]]; then \
		echo "Make \033[33m$(NAME)\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


clean:
	@make clean -C $(LDIR) 2> tmp.log
	@rm -rf $(OBJS) 2> tmp.log
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@make fclean -C $(LDIR) 2> tmp.log
	@rm -rf $(NAME) 2> tmp.log
	@echo "\033[31m> Clear $(NAME)\033[0m"

re: fclean all
