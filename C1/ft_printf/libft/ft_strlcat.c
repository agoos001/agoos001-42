/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:02:32 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/14 17:20:59 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;
	size_t	src_len;

	if (!dstsize)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	dstsize = dstsize - dst_len - 1;
	if (dstsize > src_len)
		dstsize = src_len;
	while (i < dstsize && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
// #include<stdio.h>	
// #include <string.h>
// int main() 
// {
//
// 	char mem[13] = "Hello ";
// 	ft_strlcat(mem, mem, 13);
// 	printf("cpy: %s\n", mem);
//
// 	#undef strlcat
// 	char mem1[12] = "Hello ";
// 	strlcat(mem1, mem1, 12);
// 	printf("org: %s\n", mem1);
// }
// agoos is the best
