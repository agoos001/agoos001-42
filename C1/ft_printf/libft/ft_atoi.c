/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:50:19 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/16 21:09:43 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*(nptr++) == '-')
			sign = -1;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (result > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			return ((int)LONG_MAX);
		}
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
// #include <stdio.h>
// int main()
// {
// 	printf("org: %d\n", atoi("\t\v\f\r\n \f-06050"));
// 	printf("cpy: %d\n", ft_atoi("\t\v\f\r\n \f-06050"));
//
// }
