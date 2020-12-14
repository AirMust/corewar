# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/12/15 00:31:30 by airat_must       ###   ########.fr        #
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

SRC_VM = vm_create.c
SRC_VM += vm_bytes.c
SRC_VM += vm_error.c
SRC_VM += vm_free.c
SRC_VM += vm_preparation.c
SRC_VM += vm_preparation_help.c
SRC_VM += vm_validation.c
SRC_VM += vm_validation_help.c


SOURCES_VM = $(addprefix $(SDIR_VM)/,$(SRC_VM))
OBJECTS_VM = $(addprefix $(ODIR_VM)/,$(SRC_VM:.c=.o))

.PHONY: clean fclean all re $(LIBFT)

all : $(NAME) Makefile
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) : $(LIBFT) $(OBJECTS) $(OBJECTS_VM) $(INCLUDES)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)  $(OBJECTS_VM) -I $(IDIR) $(LIBFT)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) : Makefile
	@make -C $(LDIR) 2> tmp.log

# /*
# ** ====================== MAKE VM ==========================
# */
$(ODIR_VM)/%.o : $(SDIR_VM)/%.c $(INCLUDES)
	@if [[ $< == src/vm/vm_create.c ]]; then \
		echo "\n > Make \033[33mvmachine\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_VM) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== SOURCE MAIN  ==========================
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
