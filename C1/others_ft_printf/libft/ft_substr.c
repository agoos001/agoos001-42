/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:25:41 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/18 11:34:06 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(void)
{
	char	*result;

	result = malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	sub_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || !len)
	{
		result = allocate();
		return (result);
	}
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	result = malloc(sub_len + 1);
	if (!result)
		return (NULL);
	while (start--)
		s++;
	ft_memcpy(result, s, sub_len);
	result[sub_len] = '\0';
	return (result);
}
/*
int main()
{
	char *str = "agoos is the best";
	char *result = ft_substr(str, 0, 17);
	int i = 0;

	write(1, &result[i], 18);
}*/
