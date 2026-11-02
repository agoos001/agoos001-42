# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/30 12:53:06 by mbihti            #+#    #+#              #
#    Updated: 2026/10/30 12:58:45 by mbihti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
# CFLAGS:= -Wall -Werror -Wextra

NAME:= get_next_line.out

SRC:= get_next_line.c get_next_line_utils.c main.c
SRC_BONUS:= get_next_line_bonus.c get_next_line_utils_bonus.c main.c
HDR:= get_next_line.h
OBJS:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
# gcc -g3 -O0 -fno-inline -fno-omit-frame-pointer \
# 	$(SRC) -o $(NAME)
bonus: $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all

.PHONY: all, clean
