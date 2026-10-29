/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:08:33 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/29 06:33:25 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_add(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_print_add(nbr / 16);
		ft_print_add(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_print_c(nbr + '0');
		else
			ft_print_c((nbr - 10) + 'a');
	}
}

static int	ft_nbr_len(unsigned long nb)
{
	int	count;

	count = 0;
	while (nb)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

int	ft_print_p(unsigned long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		count += ft_print_s(PTRNULL);
		flags->width -= 3;
		return (count);
	}
	else
	{
		count += ft_print_s("0x");
		ft_print_add(nbr);
		count += ft_nbr_len(nbr);
	}
	return (count);
}

int	g_print_ptr(void *ptr, t_flags *flags)
{
	int	count;	
	unsigned long p_nbr;

	p_nbr = (unsigned long) ptr;
	count = 0;

	if (flags->left)
		count += ft_print_p(p_nbr, flags);
	if (flags->width)
	{
		count += ft_pad_width(flags->width, ft_nbr_len(p_nbr) + 2, flags->zero);	
	}
	if (!flags->left)
		count += ft_print_p(p_nbr, flags);

	return (count);
}
