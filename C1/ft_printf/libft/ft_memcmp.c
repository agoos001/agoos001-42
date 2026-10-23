/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:42:00 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/14 16:13:59 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const	void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}

// #include <memory.h>
// #include <stdio.h>
// int main()
// {
// 	char str[] = "agooa";
// 	char str1[] = "agoob";
// 	int result ;
// 	// result = ft_memcmp(NULL, str1, 5);
// 	// printf("org: %d \n", result);
//
// 	result = memcmp(str, NULL, 5);
// 	printf("cpy: %d \n", result);
// }
