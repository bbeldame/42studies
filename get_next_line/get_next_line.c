/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/26 20:07:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	str_minus(char *str, int index, int length)
{
	ft_memmove(str, str + index + 1, length - index);
}

void	freeelem(t_const *fst, int fd)
{
	t_cont	*tmp;

	while (tmp->next)
	{
		if (tmp->fd == fd)
		{
				
		}
		tmp = tmp->next;
	}
}

t_cont	*getlist(t_cont *fst, int fd)
{
	t_cont	*tmp;
	t_cont	*tmpnext;

	tmp = fst;
	if (!tmp)
	{
		tmp = (t_cont *)malloc(sizeof(t_cont));
		return (tmp);
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->next->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = (t_cont *)malloc(sizeof(t_cont));
		tmp->fd = fd;
	}
	return (tmp);
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
	static t_cont	*lst;

	ret = 1;
	lst = getlist(lst, fd);
	if (!(lst->ctt = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while (contains_stop(lst->ctt) == -1 && ret)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		lst->ctt = ft_strjoin(lst->ctt, buffer);
	}
	if (!ret && contains_stop(lst->ctt) == -1)
		if (!ft_strlen(lst->ctt))
			return (0);
	if (!(newline = (char *)malloc(sizeof(char) * contains_stop(lst->ctt))))
		return (-1);
	ft_strncpy(newline, lst->ctt, contains_stop(lst->ctt));
	str_minus(lst->ctt, contains_stop(lst->ctt), ft_strlen(lst->ctt));
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
		return (-1);
	ft_strncpy(*line, newline, ft_strlen(newline));
	free(newline);
	return (1);
}
