/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <mbihti@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 06:38:37 by mbihti            #+#    #+#             */
/*   Updated: 2026/08/16 07:13:43 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*end;

	end = s + ft_strlen(s);
	while (end >= s)
	{
		if ((char)*end == (char)c)
			return ((char *)end);
		if (end == s)
			break ;
		end--;
	}
	return (NULL);
}
