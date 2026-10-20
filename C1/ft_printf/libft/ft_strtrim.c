/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:43:25 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/19 09:41:08 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	last = ft_strlen(s1);
	while (first < last && ft_strrchr(set, s1[last]))
		last--;
	result = ft_substr(s1, first, (last - first + 1));
	return (result);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "aaaaagoos is the besaaaaa";
// 	char *result = ft_strtrim(str, "aaaaagoos is the besaaaaa");
// 	printf("result: %s\n", result);
// 	return (0);
// }
