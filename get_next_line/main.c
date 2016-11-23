/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/23 19:40:43 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*str;
//	char	*str2;
	int		i;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (get_next_line(fd, &str))
	{
		i++;
		ft_putstr(str);
		ft_putchar('\n');
	}
	if (close(fd) == -1)
		ft_putstr("Close() failed\n");
	printf("\n Go sur le fichier 2 :\n");
/*	fd = open("file2.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (get_next_line(fd, &str2))
	{
		i++;
		ft_putstr(str2);
		ft_putchar('\n');
	}
	if (close(fd) == -1)
		ft_putstr("Close() failed\n");
*/	return (1);
}
