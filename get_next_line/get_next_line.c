/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 23:27:07 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	str_minus(char *str, int index, int length)
{
	ft_memmove(str, str + index + 1, length - index);
}

t_cont	*getlist(t_cont *fst, int fd)
{
	t_cont	*tmp;

	tmp = fst;
	if (!tmp)
	{
//		printf("If 29\n");
		tmp = (t_cont *)malloc(sizeof(t_cont));
		tmp->fd = fd;
		tmp->ctt = "\0";
		return (tmp);
	}
	else
	{
//		printf("Else 34\n");
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = (t_cont *)malloc(sizeof(t_cont));
		tmp->fd = fd;
		tmp->ctt = "\0";
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
		{
//			printf("CS : On retourne i = %d\n", i);
			return (i);
		}
		i++;
	}
//	printf("CS : On retourne -1\n");
	return (-1);
}

int		isfinish(int ret, int fd, char *ctt)
{
	char	minibuff[2];
	int		miniret;

	miniret = read(fd, minibuff, 1);
	if (!miniret)
		return (0);
	minibuff[1] = '\0';
	ctt = ft_strjoin(ctt, minibuff);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*newline;
	static t_cont	*lst;

	ret = 1;
//	ft_putstr("Rentre dans gnl\n");
	lst = getlist(lst, fd);
//	printf("Lst->ctt 74 = %s\n", lst->ctt);
	if (!lst->ctt)
		if (!(lst->ctt = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while (contains_stop(lst->ctt) == -1 && ret)
	{
//		printf("On est la\n");
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
//		printf("ret = %d\n", ret);
//		printf("buffer = %s\n", buffer);
		buffer[ret] = '\0';
//		printf("Buffer = %s\n", buffer);
		lst->ctt = ft_strjoin(lst->ctt, buffer);
	}
	printf("ret = %d\n", ret);
	ret = isfinish(ret, fd, lst->ctt);
	printf("ret = %d\n", ret);
//	printf("   ---   \nLine 83, ctt = \n%s\n   ---   \n", lst->ctt);
	if (!ret && contains_stop(lst->ctt) == -1)
	{
		printf("Ici\n");
		if (!ft_strlen(lst->ctt))
		{
			return (0);
		}
	}
//	ft_putstr("J'ai pas retourne 0\n");
	if (!(newline = (char *)malloc(sizeof(char) * contains_stop(lst->ctt))))
		return (-1);
	ft_strncpy(newline, lst->ctt, contains_stop(lst->ctt));
//	printf("Newline 95 = %s\n", newline);
//	la a la place de str minus je dois faire une fonction propre qui free et refait lst->ctt
	str_minus(lst->ctt, contains_stop(lst->ctt), ft_strlen(lst->ctt));
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
		return (-1);
//	printf("Newline 99 = %s\n   ---\n", newline);
	ft_strncpy(*line, newline, ft_strlen(newline));
	free(newline);
	return (ret) ? 1 : 0;
}
