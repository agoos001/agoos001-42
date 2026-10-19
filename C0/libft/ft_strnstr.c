/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 07:15:24 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/17 06:33:30 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len < 1)
		return ((char *)big);
	while (len && *big)
	{
		if (len < little_len)
			break ;
		i = 0;
		while (little[i] && little[i] == big[i])
			i++;
		if (i == little_len)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
//
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *result;
// 	result = ft_strnstr(NULL, "is", 0);
// 	printf("result: %s \n", result);
// 	result = strnstr(NULL, "is", 0);
// 	printf("result: %s \n", result);
//
// 	// result = ft_strnstr("agoos is the best", "is", 20);
// 	// printf("result: %s \n", result);
// 	//
// 	// result = ft_strnstr("agoos is the best", "", 17);
// 	// printf("result: %s \n", result);
// 	//
// 	// result = ft_strnstr("agoos is the best", "is", 0);
// 	// printf("result: %s \n", result);
// 	//
// 	// result = ft_strnstr("agoos is the best", "t", 17);
// 	// printf("result: %s \n", result);
// 	//
// 	// result = ft_strnstr("agoos is the best", "a", 17);
// 	// printf("result: %s \n", result);
// }
