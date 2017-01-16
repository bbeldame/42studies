/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:20:23 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/24 17:47:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((str = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
			return (NULL);
		ft_strcat(ft_strcpy(str, s1), s2);
		return (str);
	}
	str = NULL;
	return (str);
}
