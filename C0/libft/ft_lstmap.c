/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:00:06 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/25 13:00:37 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*set;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			if (del)
				del(set);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void print(void *ptr)
// {
// 	printf("node: %d \n", *(int *)ptr);
// }
// int	main()
// {
// 	t_list *nod1 = NULL;
//
// 	int i;
// 	for (i = 0; i < 10; i++)
// 	{
// 		int* mem = malloc(4);
// 		*mem = i;
// 		ft_lstadd_back(&nod1, ft_lstnew(mem));
// 	}
//
// 	ft_lstiter(nod1, print);
// }
