/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:21:46 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/10 03:50:40 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int e;
	int flag;

	i = 0;
	flag = 0;
	e = ft_strlen(little);
	if (e == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + flag] == little[flag])
		{
			if (flag == e - 1)
				return (char *)big + i;
			flag++;
		}
		flag = 0;
		i++;
	}
	return (NULL);
}
