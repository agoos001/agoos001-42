/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 06:50:17 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/17 07:02:42 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	int result;
	result = strncmp("agoos is the best", "agoos is the aest", 17);
	printf("result: %d\n", result);

	result = strncmp("agoos is the best", "agoos is the aest", 14);
	printf("result: %d\n", result);

	result = strncmp("agoos is the best", "agoos is the aest", 10);
	printf("result: %d\n", result);

	return 0;
}*/
