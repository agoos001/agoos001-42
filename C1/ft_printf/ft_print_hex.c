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

int	ft_print_h(char *s_nbr,unsigned n,  t_flags *flags)
{
	int	count;

	count = 0;

	return (count);
}

int	ft_print_prefix(int	is_upper)
{
	int	count;

	count = 0;
	if (is_upper)
		count += ft_print_s("0X");
	else
		count += ft_print_s("0x");
	return (count);
}

int	g_print_hex(unsigned long nb, int is_upper, t_flags *flags)
{
	int		count;
	char	*s_nbr;

	count = 0;
	if (nb == 0 && flags->precision == 0)
	{
		count += ft_pad_width(flags->width, 0, 0);
		return (count);
	}
	s_nbr = ft_xtoa(nb, is_upper);
	if (!s_nbr)
		return (0);
	if (flags->hash && nb == 0)
		count += ft_print_prefix(is_upper);
	if (flags->left)



	
}
 
