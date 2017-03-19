/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:33:01 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/19 21:04:40 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int  mathsequence(DL a, DL b, DL oa, DL ob)
{
	DL      aa;
	DL      bb;
	int     iteration;

	iteration = 0;
	while (iteration < MAX_ITER)
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

void        draw_mandelbrot(t_env *e, int x, int y)
{
	DL      a;
	DL      b;
	int		iteration;
	int		color;
	int		basecolor;

	while (x++ < WIDTH && (y = 0) != 1)
		while (y++ < HEIGHT)
		{
			a = ft_map(x, WIDTH, MIN_RANGE / 1, MAX_RANGE / 1);
			b = ft_map(y, HEIGHT, MIN_RANGE / 1, MAX_RANGE / 1);
			iteration = mathsequence(a, b, a, b);
			basecolor = 0x6A0EB3;
			color = ft_map(iteration, MAX_ITER, basecolor << 4, basecolor >> 4);
			color = ft_map(iteration, MAX_ITER, color << 8, color >> 8);
			color = ft_map(iteration, MAX_ITER, color << 12, color >> 12);
			if (iteration == MAX_ITER)
				color = ft_map(x, WIDTH, 0x00FF00 << 4, 0x00FF00 >> 4);
			put_pxl(e, x, y, color);
		}
}