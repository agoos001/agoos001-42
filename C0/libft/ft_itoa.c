/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:02:13 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/15 13:02:17 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*result;
	size_t	len;

	nb = n;
	if (nb < 0)
		nb = -nb;
	if (n == 0)
		return (ft_strdup("0"));
	len = n_len((long)n);
	result = malloc (len + 1);
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	while (nb)
	{
		result[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
// #include <stdio.h>
// #include <limits.h>
//
// int main()
// {
// 	printf("result: %s\n", ft_itoa(0131));
// 	printf("result: %s\n", itoa(0));
// // 	printf("result: %s\n", ft_itoa(-1));
// // 	printf("result: %s\n", ft_itoa(INT_MAX));
// // 	printf("result: %s\n", ft_itoa(INT_MIN));
// // 	return (0);
// }
