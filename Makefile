# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2016/01/10 13:49:58 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

MAKE = make
CC = clang++
RM = /bin/rm
SDIR = srcs/

SRC = $(SDIR)main.cpp \
	$(SDIR)Screen.cpp \
	$(SDIR)Character.cpp

OBJ = $(SRC:.cpp=.o)
INC = -I includes -I /usr/local/opt/ncurses/include
LIB = -L /usr/local/opt/ncurses/lib
CFLAGS = -Wall -Wextra -Werror
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
C = \033[36;1m
Z = \033[0m
A = $(R)[$(B)$(NAME)$(R)]----->\033[0m


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) -lncurses
	@echo "$(A)$(R)[$(Y)Compilation$(R):$(G) ✓$(R)]$(Z)"
	@echo "\n$(Y)-----------------------------------"
	@echo "$(Y)------- $(R)[$(B)$(NAME) $(G)created$(R)]$(Y) --------$(Z)"
	@echo "$(Y)-----------------------------------"
	@echo "\n$(Y)------------ $(P)Enjoy $(C);)$(Y) -------------$(Z)"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ)
	@echo "$(R)[$(Y)Clean$(R): $(G)✓$(R)]$(Z)"

fclean: clean
	@$(RM) -rf $(NAME)
	@echo "$(R)[$(Y)Fclean$(R): $(G)✓$(R)]$(Z)"

re: fclean all

.PHONY: all name clean fclean re
