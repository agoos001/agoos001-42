/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 06:00:09 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/16 06:37:35 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *result;
// 	char *str = "ü";
//
// 	result = ft_strchr(str, 129);
// 	printf("result : %c \n", *result);
//
// 	// result = strchr(str, 129);
// 	// printf("result : %c \n", *result);
//
// 	return (0);
// }
