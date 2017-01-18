/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:15:31 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/09 20:49:43 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*l;
	int		i;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (ft_strlen(little) < 1)
		return (b);
	while (b[i])
	{
		if (ft_strncmp(b + i, little, ft_strlen(little)) == 0)
			return (b + i);
		i++;
	}
	return (NULL);
}
