/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:35:35 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/24 17:51:14 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_isneg(int *negflag, int *n, int *total)
{
	*total = *n;
	if (*n < 0)
	{
		*n = *n * -1;
		*negflag = 1;
		return (0);
	}
	*negflag = 0;
	return (1);
}

static char					*ft_choose(int n)
{
	char	*temp;

	if (n == -2147483648)
	{
		temp = "-2147483648";
		return (temp);
	}
	temp = "0";
	return (temp);
}

char						*ft_itoa(int n)
{
	int		total;
	int		lenght;
	char	*str;
	int		negflag;

	if (n == -2147483648 || n == 0)
		return (ft_strdup(ft_choose(n)));
	lenght = 2 - ft_isneg(&negflag, &n, &total);
	while (total)
	{
		lenght++;
		total = total / 10;
	}
	if ((str = (char *)malloc(sizeof(char) * lenght)) == NULL)
		return (NULL);
	str[--lenght] = '\0';
	while (lenght--)
	{
		str[lenght] = n % 10 + '0';
		n = n / 10;
	}
	if (negflag)
		str[0] = '-';
	return (str);
}
