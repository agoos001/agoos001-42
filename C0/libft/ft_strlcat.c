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

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	dstsize = dstsize - dst_len - 1;
	if (dstsize > src_len)
		dstsize = src_len;
	while (i < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// #include<stdio.h>	
// #include <string.h>
// int main() 
// {
//
// 	char mem[60] = "Hello ";
// 	char dst[20] = "agoos ";
// 	int result = ft_strlcat(dst, mem, 0);
// 	printf("cpy: %s result: %d\n", mem, result);
//
// 	#undef strlcat
// 	char mem1[12] = "Hello ";
// 	char dst1[20] = "agoos ";
// 	result = strlcat(dst1, mem1, 0);
// 	printf("org: %s result: %d\n", mem1, result);
// }
// agoos is the best
