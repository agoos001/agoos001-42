/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:45:31 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/26 14:44:32 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(const char *s_nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision >= 0)
	{
		count += ft_pad_width(flags->precision, ft_strlen(s_nbr), 1);
		count += ft_print_s(s_nbr);
		return (count);
	}
	count = ft_print_s(s_nbr);
	return (count);
}

static int	ft_nbr_len(unsigned int nb)
{
	int	count;
	
	count = 0;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	g_print_unsigned(unsigned int nbr, t_flags *flags)
{
	int count;
	char	*s_nbr;
	count = 0;
	s_nbr = ft_utoa(nbr);
	if (!s_nbr)
		return (0);
	if (flags->precision == 0 && nbr == 0)
	{
		count += ft_pad_width(flags->width, 0, flags->zero);
		return (count);
	}
	if (flags->left == 1)
		count += ft_print_u(s_nbr, flags);
	if (flags->width != -1)
		count += ft_pad_width(flags->width, ft_strlen(s_nbr), flags->zero);
	if (flags->left == 0)
		count += ft_print_u(s_nbr, flags);
	return (count);
}
