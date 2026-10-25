/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 08:16:41 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/23 09:05:59 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_pre_width(const char *s, int precision, int width)
{
	int	count;
	size_t s_len;

	count = 0;
	s_len = ft_strlen(s);
	if (s_len < precision)
		precision = s_len;
	if (width != -1 && precision > width)
		precision = width;
	while (*s && count < precision)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

int	ft_print_string(const char *s)
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

int	ft_print_str(const char *str, t_flags *flags)
{
	int	count;

	count = 0;
	
	
	if (flags->left)
		count += ft_print_string(str);
	if (flags->precision >= 0)
		count += ft_print_s_pre_width(str, flags->precision, 
								flags->width);
	else if (flags->precision && !flags->left)
		count += ft_print_string(str);
	return (count);
}



