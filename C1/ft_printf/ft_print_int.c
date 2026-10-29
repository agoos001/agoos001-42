/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:30:26 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/29 09:05:42 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_int(char *s_nbr, int nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_print_c('-');
		flags->width -= 1;
	}
	if (flags->plus && ft_isdigit(s_nbr[0]))
	{
		count += ft_print_c('+');
		flags->width -= 1;
	}
	if (flags->space && ft_isdigit(s_nbr[0]))
	{
		count += ft_print_c(' ');
		flags->width -= 1;
	}
	count += ft_print_s_int(s_nbr, flags);
	free (s_nbr);
	return (count);
}

int	g_print_int(int nbr, t_flags *flags)
{
	int		count;
	char	*s_nbr;
	long	nb;

	count = 0;
	nb = nbr;
	if (nb < 0)
		nb = -nb;
	s_nbr = ft_itoa_(nb);
	if (!s_nbr)
		return (0);
	count += ft_print_int(s_nbr, nbr, flags);
	return (count);
}

int	ft_print_s_int(const char *str, t_flags *flags)
{
	int	count;
	int	s_len;

	s_len = ft_strlen(str);
	count = 0;
	if (flags->left)
	{
		if (flags->precision > 0)
			count += ft_pad_width(flags->precision, s_len, 1);
		count += ft_print_s(str);
	}
	else
	{
		if (s_len < flags->precision)
			count += ft_pad_width(flags->width, flags->precision, flags->zero);
		else
			count += ft_pad_width(flags->width, s_len, flags->zero);
	}
	if (!flags->left)
	{
		if (flags->precision > 0)
			count += ft_pad_width(flags->precision, s_len, 1);
		count += ft_print_s(str);
	}
	return (count);
}
