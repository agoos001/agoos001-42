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

void	memset_(void *buffer, int c, size_t n)
{
	char	*buff;

	if (!buffer)
		return ;
	buff = buffer;
	while (--n)
	{
		*buff = (char)c;
		buff++;
	}
}

char	*read_(char *buffer, int fd)
{
	char	*new_buff;
	int		bytes_read;

	new_buff = malloc (BUFFER_SIZE + 1);
	if (!new_buff)
		return (NULL);
	new_buff[0] = '\0';
	while (!strchr_gnl(new_buff))
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
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

char	*parce_line(char *buffer)
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = read_(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = parce_line(buffer);
	if (!line || !line[0])
	{
		free(buffer);
		return (NULL);
	}
	fix_buffer(buffer);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
