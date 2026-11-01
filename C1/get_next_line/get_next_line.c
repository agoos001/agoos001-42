/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:56:08 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/30 21:03:47 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <memory.h>

char	*read_(char *buffer, int fd)
{
	char	*new_buff;
	int		bytes_read;
	
	new_buff = malloc(BUFFER_SIZE + 1);
	if (!new_buff)
		return (NULL);
	while (!strchr_gnl(new_buff))
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		new_buff[bytes_read] = '\0';
		buffer = strjoin_free(buffer, new_buff);
		// if (!buffer)
		// 	return (NULL);
	}
	free(new_buff);
	return (buffer);
}

char *parce_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = str_len_gnl(buffer);
	printf("len: %d \n", len);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	printf("buffer: %s \n", buffer);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = read_(buffer, fd);
	if (!buffer)
		return (NULL);
	line = parce_line(buffer);
	if (!line || !line[0]) return (NULL);
	fix_buffer(buffer);
	return (line);
}
