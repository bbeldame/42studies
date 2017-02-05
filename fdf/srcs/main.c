/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/30 19:56:16 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		err_found("usage : fdf input_map");
	if (!(e = initenv(av[1])))
		err_found("a problem occured during the parsing.");
	mlx_fill_image(e, C_WHITE);
	rot_x(e, X_DEF);
	rot_y(e, Y_DEF);
	rot_z(e, Z_DEF);
	draw_fdf(e);
	mlx_loop(e->mlx);
	return (1);
}
