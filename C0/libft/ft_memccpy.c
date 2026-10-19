/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:24:12 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/14 15:21:16 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest || !src)
		return (NULL);
	d = dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*d = *s;
		if (*d == (unsigned char)c)
			return (++d);
		d++;
		s++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char *str = "agoos is the best";
	char result[20];
	ft_memccpy(result, str, 'i', 17);
	printf("result: %s\n", result);
}*/
