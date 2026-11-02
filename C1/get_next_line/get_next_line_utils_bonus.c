/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 20:46:08 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/30 21:01:06 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	if (s1)
		s1_len = str_len_chr(s1, '\0');
	s2_len = str_len_chr(s2, '\0');
	result = malloc (s1_len + s2_len + 1);
	if (!result)
		return (free(s1), NULL);
	result[cpy_string(result, s1, s2)] = '\0';
	return (free(s1), result);
}

void	fix_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = str_len_chr(buffer, '\n');
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[j + i];
		j++;
	}
	
	buffer[j] = '\0';
}

size_t	cpy_string(char *result, char *s1, char *s2)
{
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = str_len_chr(s1, '\0');
	s2_len = str_len_chr(s2, '\0');
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

size_t	str_len_chr(char *str, char c)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	if (*str == c && c != '\0')
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
