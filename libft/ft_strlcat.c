/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:29:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/13 17:56:25 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dst);
	if (i >= size)
		return (size + ft_strlen(src));
	dst = ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (i + ft_strlen(src));
}
