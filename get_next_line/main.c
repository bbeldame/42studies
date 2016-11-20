/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/20 17:44:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &str))
	{
//		ft_putstr(str);
		ft_putchar('\n');
	}
	if (close(fd) == -1)
		ft_putstr("Close() failed\n");
	return (1);
}
