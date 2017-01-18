/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:10:10 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/13 18:10:35 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	int		i;

	ss = (char *)s;
	i = 0;
	while (ss[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == s[i])
			return (ss + i);
		i--;
	}
	return (NULL);
}
