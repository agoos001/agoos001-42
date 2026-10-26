/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:30:26 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/25 20:19:23 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_print_int(int	nbr, t_flags *flags)
{
	int	count;
	char *s_nbr;
	
	s_nbr = ft_itoa(nbr);
	g_print_str(s_nbr, flags);
	count = ft_strlen(s_nbr);
	return (count);
}

