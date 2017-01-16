/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 21:18:58 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/24 16:34:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_display_file(char *str)
{
	int			fd;
	int			ret;
	int			buf_size;
	char		buf[11];

	buf_size = 10;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	ret = read(fd, buf, buf_size);
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = read(fd, buf, buf_size);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
