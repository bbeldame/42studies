/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:40:20 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/09 17:35:09 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret;

	ret = (char*)malloc(sizeof(*ret) * (ft_strlen(s1) + 1));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	return (ret);
}
