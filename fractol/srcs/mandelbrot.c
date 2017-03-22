/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:33:01 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 20:30:26 by bbeldame         ###   ########.fr       */
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
		a = aa + oa;
		b = bb + ob;
		if (a + b > LIMIT)
			return (iteration);
		iteration++;
	}
	return (iteration);
}

void		draw_mandelbrot(t_env *e, int x, int y)
{
	DL		a;
	DL		b;
	int		iteration;
	int		color;
	int		basecolor;

	while (x++ < WIDTH && (y = 0) != 1)
		while (y++ < HEIGHT)
		{
			a = ft_map(x - 1, WIDTH, (MIN_RANGE) / ZOOM, (MAX_RANGE) / ZOOM);
			b = ft_map(y - 1, HEIGHT, (MIN_RANGE) / ZOOM, (MAX_RANGE) / ZOOM);
			iteration = mathsequence(a, b, e);
			basecolor = 0x6A0EB3;
			color = ft_map(iteration, MAXITER, basecolor << 2, basecolor >> 4);
			color = ft_map(iteration, MAXITER, color << 2, color >> 8);
			color = ft_map(iteration, MAXITER, color << 6, color >> 10);
			if (iteration == MAXITER)
				color = ft_map(x, WIDTH, 0x8DFF45 << 4, 0xA3FFD3 >> 4);
			put_pxl(e, x - 1, y - 1, color);
		}
}
