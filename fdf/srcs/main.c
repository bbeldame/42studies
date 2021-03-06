/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/26 19:49:21 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		err_found("usage : fdf input_map.fdf");
	if (ft_strncmp(ft_strrev(av[1]), "fdf.", 4) != 0)
		err_found("usage : fdf input_map.fdf");
	ft_strrev(av[1]);
	if (!(e = initenv(av[1])))
		err_found("a problem occured during the parsing.");
	rot_x(e, X_DEF);
	rot_y(e, Y_DEF);
	rot_z(e, Z_DEF);
	draw_fdf(e);
	mlx_loop(e->mlx);
	return (1);
}
