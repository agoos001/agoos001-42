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

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	tm = 0;
	char		*line;
	int			bytes_read;

	if (!tm)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		tm = 1;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0])
	{
		line = strjoin_free(line, buffer);
	}
	while (!strchr_gnl(line))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		line = strjoin_free(line, buffer);
		if (!line)
			return (NULL);
	}
	if (!line || !line[0])
		return (NULL);
	fix_buffer(buffer);
	if (bytes_read <= 0)
		return (free(buffer), line);
	return (line);
}
