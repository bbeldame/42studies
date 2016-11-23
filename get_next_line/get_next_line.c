/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/23 19:41:23 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	str_minus(char *str, int index, int length)
{
	ft_memmove(str, str + index + 1, length - index);
}

int		contains_stop(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || !str[i])
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*newline;
	static char		*str;

	ret = 1;
	if (!str)
		if (!(str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while (contains_stop(str) == -1 && ret)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (!ret && contains_stop(str) == -1)
		if (!ft_strlen(str))
			return (0);
	if (!(newline = (char *)malloc(sizeof(char) * contains_stop(str))))
		return (-1);
	ft_strncpy(newline, str, contains_stop(str));
	str_minus(str, contains_stop(str), ft_strlen(str));
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
		return (-1);
	ft_strncpy(*line, newline, ft_strlen(newline));
	free(newline);
	return (1);
}
