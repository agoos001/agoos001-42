/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 09:32:10 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/23 12:14:32 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc (sizeof(struct s_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
//
// #include <stdio.h>
// int main()
// {
// 	char *str = "agoos is the best";
// 	t_list *result = ft_lstnew(str);
// 	printf("result: %s\n", (char *)result->content);
// }
