/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:55:00 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/26 18:17:57 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_pxl(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		pos = (x * e->cimg.bpp / 8) + (y * e->cimg.sl);
		e->img[pos] = color % 256;
		e->img[pos + 1] = (color >> 8) % 256;
		e->img[pos + 2] = (color >> 16) % 256;
	}
}

static DL	ft_map(DL x, DL size, DL min, DL max)
{
	return ((x / size) * (max - min) + min);
}

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
		bb = fabsl(bb);
		a = aa + oa;
		b = bb + ob;
		if (a + b > LIMIT)
			return (iteration);
		iteration++;
	}
	return (iteration);
}

void		draw_burningship(t_env *e, int x, int y)
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
