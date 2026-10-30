/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:24:22 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/30 12:46:12 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = str_len_gnl(s1);
	s2_len = str_len_gnl(s2);
	result = malloc (s1_len + s2_len + 1);
	if (!result)
		return (free(s1), NULL);
	result[cpy_string(result, s1, s2)] = '\0';
	free(s1);
	return (result);
}

void	fix_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = str_len_gnl(buffer);
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[j + i];
		j++;
	}
}

size_t	cpy_string(char *result, char *s1, char *s2)
{
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = str_len_gnl(s1);
	s2_len = str_len_gnl(s2);
	len = 0;
	while (len < s1_len)
	{
		result[len] = s1[len];
		len++;
	}
	while (len - s1_len < s2_len)
	{
		result[len] = s2[len - s1_len];
		len++;
	}
	return (len);
}

size_t	str_len_gnl(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		len++;
	return (len);
}

char	*strchr_gnl(char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}
