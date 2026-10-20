# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 20:29:21 by mbihti            #+#    #+#              #
#    Updated: 2026/10/19 20:45:41 by mbihti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
# FLAGS:= -Wall -Werror -Wextra

SRC:= ft_print_char.c ft_flags_utils.c ft_printf.c 
OBJS:= $(SRC:.c=.o)
HEADER:= ft_printf.h

NAME:= ft_printflib.a

all: $(NAME)

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
