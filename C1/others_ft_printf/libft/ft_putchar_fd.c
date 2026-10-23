/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:53:12 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/19 15:37:37 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
	ft_putchar_fd('a', 1);
	write(10, "\n", 1);

	ft_putchar_fd('b', 2);
	write(2, "\n", 1);

	ft_putchar_fd('c', 0);
	write(2, "\n", 1);

	ft_putchar_fd('d', 3);
	write(2, "\n", 1);

	ft_putchar_fd('e', 10);
	write(2, "\n", 1);
}*/
