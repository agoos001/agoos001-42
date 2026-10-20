/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 16:06:22 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/17 16:39:06 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_len;	

	if (!s)
		return NULL;
	s_len = ft_strlen(s);
	result = malloc(s_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s, s_len + 1);
	return (result);
}
/*
#include <stdio.h>
int main() 
{
	char *str = "agoos is the best";
	char *result = ft_strdup(str);
	printf("result: %s\n", result);
}
*/
