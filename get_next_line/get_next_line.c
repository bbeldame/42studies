/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/20 17:44:43 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		buffer_realloc(const int fd, char *buffer)
{
	int		ret;
	while (ret = read(fd, buffer, BUFF_SIZE))
	{
		
	}

}

void	buffer_minus(char *buffer, int index, int length)
{
	ft_memmove(buffer, buffer + index, length - index);
	ft_bzero(buffer + ft_strlen(buffer) - index, ft_strlen(buffer) - index);
}

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
	static char		buffer[BUFF_SIZE + 1];
	int				ret;
	char			*newline;

	if (!ft_strlen(buffer))
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
//	printf("nb chara of fst line = %d\n", contains_stop(buffer, ret));
	if (contains_stop(buffer, ret) != -1)
	{
		if (!(newline = (char *)malloc(sizeof(char) * contains_stop(buffer, ret))))
			return (-1);
		ft_strncat(newline, buffer, contains_stop(buffer, ret) + 1);
//		printf("\n\n%s\n\n",buffer);
		buffer_minus(buffer, contains_stop(buffer, ret), ret);
		printf("\n\n%s\n\n",buffer);
		return (0);
		ft_strcpy(*line, newline);
		return (1);
	}
	else
	{
		return (0);
	}
}
