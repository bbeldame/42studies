/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/15 20:00:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_env *e;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage : fdf input_map");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	e = initenv(fd);
	return (1);
}
