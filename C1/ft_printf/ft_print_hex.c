/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:31:04 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/27 09:44:08 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_h(char *s_nbr, t_flags *flags)
{
	int		count;
	size_t	s_len;

	count = 0;
	s_len = ft_strlen(s_nbr);
	if (flags->precision > 0)
	{
		count += ft_pad_width(flags->precision, s_len, 1);
	}
	count += ft_print_s(s_nbr);
	return (count);
}

int	ft_print_prefix(int is_upper)
{
	int	count;

	count = 0;
	if (is_upper)
		count += ft_print_s("0X");
	else
		count += ft_print_s("0x");
	return (count);
}

int	g_print_hex(unsigned int nb, int is_upper, t_flags *flags)
{
	int		count;
	char	*s_nbr;
	size_t	s_len;

	count = 0;
	if (nb == 0 && flags->precision == 0)
	{
		count += ft_pad_width(flags->width, 0, 0); // -1 => "0"
		return (count);
	}
	s_nbr = ft_xtoa(nb, is_upper);
	if (!s_nbr)
		return (0);
	s_len = ft_strlen(s_nbr);
	if (flags->left)
	{
		if (flags->hash && nb != 0)
			count += ft_print_prefix(is_upper);
		count += ft_print_h(s_nbr, flags);
	}
	if (flags->hash)
		flags->width -= 2;
	if (flags->width > 0 && flags->precision > s_len)
		count += ft_pad_width(flags->width, flags->precision, 0);
	else
		count += ft_pad_width(flags->width, s_len, 0);
	if (!flags->left)
	{
		if (flags->hash && nb != 0)
			count += ft_print_prefix(is_upper);
		count += ft_print_h(s_nbr, flags);
	}
	return (count);
}
