/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:37:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/14 19:47:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(const int *tab, size_t len)
{
	int		min;
	size_t	i;

	min = tab[0];
	i = 0;
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}
