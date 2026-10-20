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

static size_t	w_count(char *s, char c);
static size_t	w_len_(char *s, char c);
static void		ft_free(char **result, size_t count);

char	**ft_split(char	*s, char c)
{
	char	**result;
	size_t	j;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (w_count(s, c) + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[j] = ft_substr(s, 0, w_len_(s, c));
			if (!result[j])
				ft_free(result, j);
			j++;
			s += w_len_(s, c);
		}
		else
			s++;
	}
	result[j] = NULL;
	return (result);
}

static void	ft_free(char **result, size_t count)
{
	while (count)
	{
		free(result[count]);
		count--;
	}
	free(result);
}

static size_t	w_len_(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			break ;
		len++;
		s++;
	}
	return (len);
}

static size_t	w_count(char *s, char c)
{
	size_t	count;
	int		x;

	x = 0;
	count = 0;
	while (*s)
	{
		if (*s == c && !x)
		{
			x = 1;
			count++;
		}
		else
			x = 0;
		s++;
	}
	return (count);
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
