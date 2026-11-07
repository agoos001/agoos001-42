/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 13:12:02 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/23 13:21:17 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
int main()
{
	t_list lst1;
	t_list lst2;
	t_list lst3;
	lst1.next = &lst2;
	lst2.next = &lst3;
	printf("result: %d", ft_lstsize(&lst1));
}*/
