/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:32:05 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/28 12:24:38 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////
// -----------------utoa--------------------
////////////////////////////////////////////
size_t	nbr_len(unsigned int nb)
{
	int	count;

	if (nb == 0)
		return (1);
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
		result[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}

/////////////////////////////////////////////
// -----------------xtoa--------------------
////////////////////////////////////////////

size_t	hex_len(unsigned long nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb)
	{
		count++;
		nb /= 16;
	}
	return (count);
}
void	ft_isupper(char *result, int is_upper)
{
	if (is_upper)
	{
		while (*result)
		{
			if (*result >= 'a' && *result <= 'z')
				*result -= 32;
			result++;
		}
	}
}

char	*ft_xtoa(unsigned long nb, int is_upper)
{
	char	*result;
	int		h_len;

	h_len = hex_len(nb);
	result = malloc(h_len + 1);
	if (!result)
		return (NULL);
	result[h_len--] = '\0';
	while (h_len >= 0)
	{
		result[h_len] = nb % 16;
		if (nb % 16 < 10)
			result[h_len] += '0';
		else
			result[h_len] += ('a' - 10);
		nb /= 16;
		h_len--;
	}
	ft_isupper(result, is_upper);
	return (result);
}
