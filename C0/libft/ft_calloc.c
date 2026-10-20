/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:54:47 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/17 16:05:59 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;
	size_t	total;

	if (size && n && n > SIZE_MAX / size)
		return (NULL);
	total = size * n;
	if (!total)
	{
		total = 1;
	}
	result = malloc(total);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int *ary = ft_calloc(10, 4);
	printf("sizeof ary: %d\n", (int)sizeof(*ary));
	int i = 0;

	while (i < 15)
	{
		ary[i] = i;
		i++;
	}
	
	i = 0;
	while (i < 20)
	{
		printf("ary[%d]: %d\n", i,  ary[i]);
		i++;
	}
	
	return 0;
}*/
