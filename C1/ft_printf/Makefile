# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 20:29:21 by mbihti            #+#    #+#              #
#    Updated: 2026/10/26 14:44:47 by mbihti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
# FLAGS:= -Wall -Werror -Wextra

SRC:= ft_print_char.c ft_flags_utils.c ft_printf.c ft_print_str.c ft_print_int.c \
	  ft_print_ptr.c ft_print_unsigned.c ft_utoa.c
OBJS:= $(SRC:.c=.o)
HEADER:= ft_printf.h

NAME:= ft_printflib.a

all: $(NAME) clean

$(NAME): $(OBJS)
	ar -rcs $(NAME)   $(OBJS)

# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)	
re: fclean all

.PHONY: all clean fclean re
