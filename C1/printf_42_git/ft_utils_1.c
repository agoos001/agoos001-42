/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:13:45 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/29 06:03:01 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa_(long nbr)
{
	char	*result;
	size_t	s_len;

	if (nbr == 0)
		return (ft_strdup("0"));
	s_len = ft_nbr_len(nbr);
	result = malloc(s_len + 1);
	if (!result)
		return (NULL);
	result[s_len--] = '\0';
	while (nbr > 0)
	{
		result[s_len] = nbr % 10 + '0';
		nbr /= 10;
		s_len--;
	}
	return (result);
}
