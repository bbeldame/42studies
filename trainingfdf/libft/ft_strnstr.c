/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:53:54 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/21 18:29:14 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	char	*big1;
	char	*big2;

	if (little[0] == '\0')
		return ((void *)big);
	while (n-- && *big)
	{
		if (*big == *little)
		{
			i = n;
			big1 = (void *)big + 1;
			big2 = (void *)little + 1;
			while (i && *big1 && *big2 && *big1 == *big2)
			{
				i--;
				big1++;
				big2++;
			}
			if (*big2 == '\0')
				return ((void *)big);
		}
		big++;
	}
	return (NULL);
}
