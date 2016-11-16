/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/16 22:46:18 by bbeldame         ###   ########.fr       */
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

	if (get_next_line(fd, &str))
	{
		ft_putchar('\n');
		ft_putstr(str);
		ft_putchar('\n');
	}

	if (close(fd) == -1)
		ft_putstr("Close() failed\n");
	return (1);
}
