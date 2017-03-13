/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:50:12 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/09 20:55:51 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	int		i;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (ft_strlen(little) < 1)
		return (b);
	while (b[i] && len > 0)
	{
		if (ft_strlen(little) > len)
			return (NULL);
		if (ft_strncmp(b + i, little, ft_strlen(little)) == 0)
			return (b + i);
		i++;
		len--;
	}
	return (NULL);
}
