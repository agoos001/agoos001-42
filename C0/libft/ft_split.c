/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:45:43 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/19 13:09:31 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	w_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	w_len_(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **result, size_t count)
{
	while (count)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

static int	fill_result(char **result, const char *s, char c)
{
	size_t	j;
	size_t	len;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len = w_len_(s, c);
		result[j] = ft_substr(s, 0, len);
		if (!result[j])
		{
			ft_free(result, j);
			return (0);
		}
		j++;
		s += len;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (w_count(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}
/*
#include <stdio.h>

int main()
{
	char *str = "agoos is the best";
	char **result = ft_split(str, ' ');
	
	int i = 0;
	while (i < 4)
	{
		printf("result[%d]: %s\n", i, result[i]);
		i++;
	}
	return 0;
}*/
