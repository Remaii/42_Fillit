#*****************************************************************************#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/06 13:02:35 by rthidet           #+#    #+#             *#
#*   Updated: 2016/02/06 12:46:25 by rthidet          ###   ########.fr       *#
#*                                                                            *#
#******************************************************************************#

NAME =
EXE = fillit
LFT = libft.a
LIBS =-L./ -lft
TEST =

HPATH = -I ./includes/

SRC = check.c get_tetri.c main.c output.c solve.c

#STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror
AR = ar -cvq libft.a
RM = rm -rf
SRCDIR = $(addprefix ./src/, $(SRC))
OBJDIR = object
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

# COLORS
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

# START RULES

all:
	@echo "$(RESET)$(GREEN)Building libft...$(WHITE)$(RESET)"
	@make -C ./libft
	@echo "$(RESET)$(YELLOW)Compiling $(SRC) in Object$(WHITE)$(RESET)"
	@$(CC) -c $(SRCDIR)
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@echo "\t$(RESET)$(RED)Building fillit...$(WHITE)$(RESET)"
	@$(CC) -o $(EXE) $(OBJ) $(LIBS) $(HPATH)
	@echo "\t\t$(GREEN)OK!$(RESET)"

clean:
	@make clean -C ./libft
	@echo "$(CYAN)Removal Object folder of $(EXE)$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@make fclean -C ./libft
	@echo "$(CYAN)Removal $(EXE)$(RESET)"
	@$(RM) $(EXE)

re: fclean
	@make all
	@make clean

# Personnal rules
go: re
	@echo "sample.fillit_wchar"
	time ./$(EXE) examples/sample.fillit_wchar
	@echo "sample.fillit_wline"
	time ./$(EXE) examples/sample.fillit_wline
	@echo "sample.fillit_wnb#"
	time ./$(EXE) examples/sample.fillit_wnb
	@echo "sample.fillit_woutput"
	time ./$(EXE) examples/sample.fillit_woutput
	@echo "sample.fillit_wshape"
	time ./$(EXE) examples/sample.fillit_wshape
	@echo "sample.fillit_bigtest"
	time ./$(EXE) examples/sample.fillit_bigtest
	@echo "sample.fillit_ok"
	time ./$(EXE) examples/sample.fillit_ok
	@echo "sample.fillit_ok2"
	time ./$(EXE) examples/sample.fillit_ok2
	@echo "sample.fillit_simple"
	time ./$(EXE) examples/sample.fillit_simple

.PHONY: all clean fclean go
