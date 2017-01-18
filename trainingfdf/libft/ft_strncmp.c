/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:36:52 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/14 18:53:20 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s2) < n)
		return (ft_memcmp(s1, s2, ft_strlen(s2) + 1));
	return (ft_memcmp(s1, s2, n));
}
