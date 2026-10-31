/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 20:46:14 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/30 21:01:06 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// # define BUFFER_SIZE

char	*get_next_line(int fd);
char	*strjoin_free(char *s1, char *s2);
char	*strchr_gnl(char *s);
size_t	str_len_gnl(char *str);
size_t	cpy_string(char *result, char *s1, char *s2);
void	fix_buffer(char *buffer);

#endif
