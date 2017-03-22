/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:36:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 20:27:38 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		choose_between_differents_fractols(t_env *e)
{
	if (e->stt.choice == MANDELBROT)
	{
		draw_mandelbrot(e, 0, 0);
	}
	else if (e->stt.choice == JULIA)
	{
		draw_julia(e, 0, 0);
	}
	else if (e->stt.choice == BURNINGSHIP)
	{
		draw_burningship(e, 0, 0);
	}
}

void			refresh(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	choose_between_differents_fractols(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
}

void			put_pxl(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->cimg.bpp / 8) + (y * e->cimg.sl);
		e->img[pos] = color % 256;
		e->img[pos + 1] = (color >> 8) % 256;
		e->img[pos + 2] = (color >> 16) % 256;
	}
}
