/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/28 20:44:55 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*delcttfromstr(char *str, int index)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - index));
	strcpy(new, str + index + 1);
	free(str);
	return (new);
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
		tmp->next = NULL;
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
		tmp->next = NULL;
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
//	ft_putstr("\n\n\n-----------Rentre dans gnl-------------\n");
	lst = getlist(lst, fd);
//	printf("Lst->ctt 74 = %s\n", lst->ctt);
//	printf("Lst->fd = %d\n", lst->fd);
	if (!line)
		return (-1);
	if (!lst->ctt)
		if (!(lst->ctt = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while (contains_stop(lst->ctt) == -1 && ret)
	{
//		printf("On est la 97\n");
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
//		printf("ret = %d\n", ret);
//		printf("buffer = %s\n", buffer);
		buffer[ret] = '\0';
//		printf("Buffer = %s\n", buffer);
		lst->ctt = ft_strjoin(lst->ctt, buffer);
	}
//	printf("ret = %d\n", ret);
//	ret = isfinish(ret, fd, lst->ctt);
//	printf("ret = %d\n", ret);
//	printf("   ---   \nLine 83, ctt = \n%s\n   ---   \n", lst->ctt);
	if (!ret && contains_stop(lst->ctt) == -1)
	{
//		printf("Ici\n");
		if (!ft_strlen(lst->ctt))
		{
			return (0);
		}
		if (!(newline = (char *)malloc(sizeof(char) * ft_strlen(lst->ctt) + 1)))
			return (-1);
//		printf("Return de ft_strlen de lst->ctt 124 : %zu\n", ft_strlen(lst->ctt));
		ft_strcpy(newline, lst->ctt);
		lst->ctt = delcttfromstr(lst->ctt, ft_strlen(lst->ctt));
		if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
			return (-1);
//		ft_putstr("-- NEWLINE = ");
//		ft_putstr(newline);
//		ft_putstr("\n");
		ft_strcpy(*line, newline);
		free(newline);
//		printf("125 : %s\n", lst->ctt);
	}
	else
	{
//		ft_putstr("J'ai pas retourne 0\n");
		if (!(newline = (char *)malloc(sizeof(char) * contains_stop(lst->ctt) + 1)))
			return (-1);
		ft_strncpy(newline, lst->ctt, contains_stop(lst->ctt) + 1);
		newline[contains_stop(lst->ctt)] = '\0';
//		printf("Newline 95 = %s\n", newline);
	//	la a la place de str minus je dois faire une fonction propre qui free et refait lst->ctt
		lst->ctt = delcttfromstr(lst->ctt, contains_stop(lst->ctt));
		if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(newline) + 1))))
			return (-1);
//		printf("Newline 99 = %s\n   ---\n", newline);
		ft_strcpy(*line, newline);
		free(newline);
//		printf("141 : %s\n", lst->ctt);
	}
	return (1);
}
