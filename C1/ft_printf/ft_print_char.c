/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:05:34 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/23 09:30:40 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left > 0)
	{
		count += ft_print_c(c);
		count += ft_pad_width(flags.width, 1, flags.zero);
	}
	if (flags.left == 0)
		count += ft_print_c(c);
	return (count);
}
