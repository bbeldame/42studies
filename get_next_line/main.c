/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/11 20:33:41 by bbeldame         ###   ########.fr       */
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
	fd2 = open("file2.txt", O_RDONLY);
	if (fd1 == -1)
		return (0);
	get_next_line(fd1, &str);
		ft_putstr(str);
		ft_putchar('\n');
	}
	if (close(fd1) == -1)
		ft_putstr("Close() failed\n");
	return (1);
}
