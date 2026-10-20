/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:09:48 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/14 06:25:20 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}

// #include <memory.h>
// #include <stdio.h>
// int main()
// {
// 	char src[] = "12345678";
// 	char src1[] = "12345678";
//
// 	ft_memcpy(src + 1,src, 5);
// 	printf("cpy: %s \n", src);
//
//
// 	memcpy(src1 + 1, src, 5);
// 	printf("org: %s", src1);
// }

