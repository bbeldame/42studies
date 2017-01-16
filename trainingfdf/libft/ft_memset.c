/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:50:09 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/19 19:53:41 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;

	if (n == 0)
		return (s);
	str = (unsigned char *)s;
	while (n--)
	{
		*str = (unsigned char)c;
		if (n)
			str++;
	}
	return (s);
}
