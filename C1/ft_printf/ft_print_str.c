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

int	ft_print_s_pre(const char *s, int precision)
{
	int	count;

	count = 0;
	while (*s && count < precision)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

int	ft_print_str(const char *s, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision > 0)
		count += ft_print_s_pre(s, flags->precision);
	return (count);
}
