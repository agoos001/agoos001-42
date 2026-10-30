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
HDR:= get_next_line.h
OBJS:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all

.PHONY: all, clean
