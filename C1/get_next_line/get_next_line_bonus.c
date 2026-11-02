/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 20:46:18 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/30 21:02:13 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*read_(char *buffer, int fd)
{
	char	*new_buff;
	int		bytes_read;
	
	new_buff = malloc (BUFFER_SIZE + 1);
	if (!new_buff)
		return (NULL);
	while (!strchr_gnl(new_buff))
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		new_buff[bytes_read] = '\0';
		buffer = strjoin_free(buffer, new_buff);
		if (!buffer)
		{
			free(new_buff);
			return (NULL);
		}
	}
	free(new_buff);
	return (buffer);
}

char *parce_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = str_len_chr(buffer, '\n');
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

// void	check_all(char **buffer)
// {
// 	if 
// }

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer[fd] = read_(buffer[fd], fd);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = parce_line(buffer[fd]);
	if (!line || !line[0]) 
	{
		free(buffer[fd]);
		return (NULL);
	}
	fix_buffer(buffer[fd]);
	if (buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}

