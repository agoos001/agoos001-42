/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:32:05 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/26 14:43:08 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t nbr_len(unsigned int nb)
{
	int count;

	count = 0;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int nb)
{
	char	*result;
	size_t	nb_len;
	size_t	i;

	nb_len = nbr_len(nb);
	result = malloc(nb_len + 1);
	result[nb_len] = '\0';
	i = nb_len - 1;
	while (nb)
	{
		result[i--] = nb % 10;
		nb /= 10;
	}
	return (result);
}
