/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/15 18:39:56 by bbeldame         ###   ########.fr       */
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
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	if (fd1 == -1)
		return (0);
	ft_putnbr(get_next_line(fd1, &str));
	ft_putstr("fd1 1 =\n");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(get_next_line(fd2, &str));
	ft_putstr("fd2 1 =\n");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(get_next_line(fd1, &str));
	ft_putstr("fd1 2 =\n");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(get_next_line(fd2, &str));
	ft_putstr("fd2 2 =\n");
	ft_putstr(str);
	ft_putchar('\n');
	close(fd1);
	close(fd2);
	return (1);
}
