/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/28 19:52:26 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	int		i;

	i = 0;
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
		return (0);
	if (get_next_line(fd1, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd2, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd1, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd2, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd1, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd2, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd1, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd2, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd2, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (get_next_line(fd1, &str) == 1)
	{
		i++;
		ft_putstr("----------------------------\n");
		ft_putstr(str);
		ft_putchar('\n');
		ft_putstr("----------------------------\n");
	}
	if (close(fd1) == -1)
		ft_putstr("Close() failed\n");
	printf("GNL returned 1 %d time(s)\n", i);
	return (1);
}
