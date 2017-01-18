/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:56:27 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/13 21:20:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitscount(int n)
{
	int				size;
	unsigned int	nb;

	size = 0;
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;
	int				minus;

	minus = 0;
	if (!(str = (char *)malloc(sizeof(char) * digitscount(n) + 1)))
		return (NULL);
	i = digitscount(n);
	if (n < 0)
	{
		minus = 1;
		nb = -n;
	}
	else
		nb = n;
	str[i--] = '\0';
	while (nb >= 10)
	{
		str[i--] = 48 + nb % 10;
		nb = nb / 10;
	}
	str[i--] = 48 + nb;
	str[i] = (minus) ? '-' : str[i];
	return (str);
}
