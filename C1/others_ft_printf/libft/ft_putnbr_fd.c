/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:00:25 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/19 18:05:51 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
		return ;
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
//
// int main()
// {
// 	ft_putnbr_fd(-555, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-555, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(555, 1);
// 	write(1, "\n", 1);
// }
