/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/16 22:46:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		contains_stop(const char *str, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (str[i] == '\n' || !str[i])
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	int			ret;
	static int	i = 0;
	int			stopindex;

	i++;
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	stopindex = contains_stop(buf, ret);
	if (stopindex != -1)
	{
		ft_putnbr(stopindex);
	}
	ft_strlcat(*line, buf, ret);
	return (1);
}
