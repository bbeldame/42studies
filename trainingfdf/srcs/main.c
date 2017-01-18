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
#include "../includes/square.h"
#include "../includes/line.h"
#include "../includes/circle.h"

int	main(void)
{
	t_env *env;
	t_f_square *sq;
	t_f_line *ln;
	t_f_circle *cr;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1920, 1080, "Ceci est un carré");
	sq = init_square(1000, 0, 0);
	ln = init_line(250);
	cr = init_circle(800, 500, 350, 250);
	ln->x1 = 100;
	ln->y1 = 100;
	ln->x2 = 1720;
	ln->y2 = 980;
	prnt_full_square(env, sq);
	prnt_line(env, ln);
	prnt_circle(env, cr);
	mlx_loop(env->mlx);
	return (1);
}
