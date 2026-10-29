/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre&width_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 07:23:23 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/29 07:23:25 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_flag(const char *str, int pos, t_flags *flags)
{
	int	count;

	count = 0;
	flags->precision = 0;
	while (str[++pos] && ft_isdigit(str[pos]))
	{
		flags->precision = flags->precision * 10 + (str[pos] - '0');
		count++;
	}
	return (count);
}

int	ft_width_flag(const char *str, int pos, t_flags *flags)
{
	int	count;

	count = 0;
	flags->width = 0;
	while (str[pos] && ft_isdigit(str[pos]))
	{
		flags->width = flags->width * 10 + str[pos++] - '0';
		count++;
	}
	return (count);
}
