# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 11:29:48 by ttshivhu          #+#    #+#              #
#*   Updated: 2018/08/25 18:55:20 by ttshivhu         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ttshivhu.filler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -Ilibft
SRC = main.c piece.c get_next_line.c
SILENT = --no-print-directory
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft $(SILENT)
	gcc $(OBJ) $(CFLAGS) -Llibft -lft -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME) \x1b[0m\n"

clean:
	make clean -C libft $(SILENT)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft $(SILENT)
	/bin/rm -f $(NAME)

re: fclean all
