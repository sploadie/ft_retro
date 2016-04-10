# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2016/04/10 20:55:32 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

MAKE = make
CC = clang++
RM = /bin/rm

SRC_NAMES = main Entity Screen Character Enemy Squad SpaceRock Bullet LightScout HeavyScout Fighter Laser Runner Star Boss Coffee

SRC_DIR = srcs/
SRC_FILES = $(addsuffix .cpp,$(SRC_NAMES))
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ = $(SRC:.cpp=.o)
INC = -I ./includes -I /usr/local/opt/ncurses/include
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

%.o:%.cpp
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ)
	@echo "$(R)[$(Y)Clean$(R): $(G)✓$(R)]$(Z)"

fclean: clean
	@$(RM) -rf $(NAME)
	@echo "$(R)[$(Y)Fclean$(R): $(G)✓$(R)]$(Z)"

re: fclean all

.PHONY: all name clean fclean re
