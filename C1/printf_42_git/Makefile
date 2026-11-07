# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 20:29:21 by mbihti            #+#    #+#              #
#    Updated: 2026/10/29 07:42:51 by mbihti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
FLAGS:= -Wall -Werror -Wextra
AR:= ar
ARFLAGS:= -rcs

SRC:= ft_print_char.c ft_flags_utils.c ft_printf.c ft_print_str.c ft_print_int.c \
	  ft_print_ptr.c ft_print_unsigned.c ft_utils.c ft_print_hex.c ft_utils_1.c  \
	  ft_pre_width_flags.c

OBJS:= $(SRC:.c=.o)
HEADER:= ft_printf.h

LIBFT_PATH:= ./libft
LIBFT:= $(LIBFT_PATH)/libft.a

NAME:= libftprintf.a


all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)
fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean bonus re
