/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 08:16:41 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/25 19:59:22 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_pre_width(const char *s, int precision)
{
	int	count;
	size_t s_len;

	count = 0;
	// s_len = ft_strlen(s);
	while (*s && count < precision)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

int	ft_print_s(const char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

int	g_print_str(const char *str, t_flags *flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags->precision >= 0 && flags->precision < 6) // the null strint padding
	{
		count += ft_pad_width(flags->width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";

	if (flags->left)
	{
	if (flags->precision >= 0)
		count += ft_print_s_pre_width(str, flags->precision);
	else
		count += ft_print_s(str);
	}
	if (flags->precision >= 0)
		count += ft_pad_width(flags->width, flags->precision, 0);
	else
		count += ft_pad_width(flags->width, ft_strlen(str), 0); 
	
	if (!flags->left && flags->precision >= 0)
		count += ft_print_s_pre_width(str, flags->precision);
	else if (!flags->left)
		count += ft_print_s(str);
	return (count);
}



