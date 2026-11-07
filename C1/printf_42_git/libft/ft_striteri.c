/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:47:23 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/16 10:31:56 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
//
// void ft_tm(unsigned int i, char *s)
// {
// 	(void)i;
// 	*s = 'a';
// }
//
// int	main()
// {
// 	char s[] = "agoos is the best";
// 	printf("org: %s \n", s);
// 	ft_striteri(s, ft_tm);
// 	printf("mod: %s \n", s);
//
// 	return (0);
// }
