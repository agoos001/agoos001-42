/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:39:04 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/31 06:19:57 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char	*strjoin_free(char *s1, char *s2);
char	*strchr_gnl(char *s);
size_t	str_len_chr(char *str, char c);
size_t	cpy_string(char *result, char *s1, char *s2);
void	fix_buffer(char *buffer);

#endif
