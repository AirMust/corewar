# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airat_must <https://github.com/AirMust>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/12/14 23:33:07 by airat_must       ###   ########.fr        #
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

SRCS = vm_main.c
SRCS += vm_bytes.c
SRCS += vm_create.c
SRCS += vm_error.c
SRCS += vm_free.c
SRCS += vm_preparation.c
SRCS += vm_preparation_help.c
SRCS += vm_validation.c
SRCS += vm_validation_help.c


SOURCES = $(addprefix $(SDIR)/,$(SRCS))
OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))


.PHONY: clean fclean all re $(LIBFT)

all : $(NAME) Makefile
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) : $(LIBFT) $(OBJECTS) $(INCLUDES)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(IDIR) $(LIBFT)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) : Makefile
	@make -C $(LDIR) 2> tmp.log


# /*
# ** ====================== SOURCE LS MAIN  ==========================
# */
$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@if [[ $< == src/vm_main.c ]]; then \
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
