/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:57:31 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/09 20:09:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (ss[i])
	{
		if ((char)c == ss[i])
			return (ss + i);
		i++;
	}
	if ((char)c == ss[i])
		return (ss + i);
	return (NULL);
}
