/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:59:49 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/14 06:17:18 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
// 	char str[20] = "agoos is the best";
// 	char *dest;
// 	int i = 0;
// 	dest = ft_memmove(str + 2 , str , 17);
// 	while (i < 17)
// 	{
// 		write(1, &dest[i], 1);	
// 		i++;
// 	}
// 	return 0;	
// }
