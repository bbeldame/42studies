/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:39:16 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_env	*e;
	int		fd;
	int		endian;
	int		sl;
	int		bpp;

	if (ac != 2)
		exit (err_found("usage : fdf input_map"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit (err_found("open failed"));
	if (!(e = initenv(fd)))
		exit (err_found("a problem occured during the parsing."));
	mlx_loop(e->mlx);
	e->img = mlx_get_data_addr(e->img_ptr, &bpp, &sl, &endian);
	e->img[800] = 0xFFFFFF;
	e->img[801] = 0xFFFFFF;
	e->img[802] = 0xFFFFFF;
	e->img[803] = 0xFFFFFF;
	e->img[804] = 0xFFFFFF;
	e->img[805] = 0xFFFFFF;
	e->img[806] = 0xFFFFFF;
	e->img[807] = 0xFFFFFF;
	e->img[808] = 0xFFFFFF;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (1);
}
