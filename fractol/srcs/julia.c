/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:55:28 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/25 19:58:45 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mathsequence(DL a, DL b, t_env *e)
{
	DL		aa;
	DL		bb;
	DL		oa;
	DL		ob;
	int		iteration;

	iteration = 0;
	oa = a;
	ob = b;
	while (iteration < MAXITER)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ft_map(e->cam.coor_x, W, MIN_RANGE_DEF, MAX_RANGE_DEF);
		b = bb + ft_map(e->cam.coor_y, H, MIN_RANGE_DEF, MAX_RANGE_DEF);
		if (a + b > LIMIT)
			return (iteration);
		iteration++;
	}
	return (iteration);
}

void		draw_julia(t_env *e, int x, int y)
{
	DL		a;
	DL		b;
	int		iteration;
	int		color;
	int		basecolor;

	while (x < W && (y = 0) != 1)
	{
		while (y < H)
		{
			a = ft_map(x, W, e->cam.minx / e->cam.zm, e->cam.maxx / e->cam.zm);
			b = ft_map(y, H, e->cam.miny / e->cam.zm, e->cam.maxy / e->cam.zm);
			iteration = mathsequence(a, b, e);
			basecolor = 0x6A0EB3;
			color = ft_map(iteration, MAXITER, basecolor << 2, basecolor >> 4);
			color = ft_map(iteration, MAXITER, color << 2, color >> 8);
			if (iteration != MAXITER)
				put_pxl(e, x, y, color);
			y++;
		}
		x++;
	}
}
