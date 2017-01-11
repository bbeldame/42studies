/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/11 20:33:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		cs(const char *str)
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

char	*dumpstr(char *str)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - cs(str)));
	if (!new)
		return (0);
	new = ft_strncpy(new, str + cs(str) + 1, ft_strlen(str) - cs(str));
	ft_bzero(str, ft_strlen(str));
	free(str);
	str = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*newline;
	static char		*str[NBMAXFD];

	ret = 1;
	if (!line || fd > NBMAXFD || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while (cs(str[fd]) == -1 && ret)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	if (!ret && cs(str[fd]) == -1)
	{
		if (!ft_strlen(str[fd]))
		{
			return (0);
		}
		if (!(newline = (char *)malloc(sizeof(char) * ft_strlen(str[fd]) + 1)))
			return (-1);
		ft_strcpy(newline, str[fd]);
		free(str[fd]);
		str[fd] = ft_strdup(str[fd] + ft_strlen(str[fd]));
		if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
			return (-1);
		ft_strcpy(*line, newline);
		free(newline);
	}
	else
	{
		if (!(newline = (char *)malloc(sizeof(char) * cs(str[fd]) + 1)))
			return (-1);
		ft_strncpy(newline, str[fd], cs(str[fd]) + 1);
		newline[cs(str[fd])] = '\0';
		str[fd] = dumpstr(str[fd]);
		if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
			return (-1);
		ft_strcpy(*line, newline);
		free(newline);
	}
	return (1);
}
