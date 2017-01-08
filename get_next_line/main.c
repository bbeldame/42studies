/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/08 19:53:11 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd1;
	char	*str;
	int		i;

	i = 0;
	fd1 = open("file.txt", O_RDONLY);
	if (fd1 == -1)
		return (0);
	while (get_next_line(fd1, &str) > 0)
	{
		if (i == 0 && strcmp(str, "1234567") != 0)
		{
			ft_putstr("kolp\n");
		}
		if (i == 1 && strcmp(str, "abcdefgh") != 0)
		{
			ft_putstr("kolpokok\n");
		}
		i++;
	}
	if (close(fd1) == -1)
		ft_putstr("Close() failed\n");
	return (1);
}
