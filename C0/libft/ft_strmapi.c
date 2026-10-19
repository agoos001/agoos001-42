/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:41:50 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/19 13:52:30 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
//
// char	ft_tm(unsigned int i, char c)
// {
// 	(void)i;
// 	(void)c;
// 	char result = 'a';
// 	return (result);
// }
//
// int	main()
// {
// 	char *s = "agoos is the best";
// 	char *result = ft_strmapi(s, ft_tm);
// 	printf("result: %s \n", result);
//
// 	return (0);
// }
