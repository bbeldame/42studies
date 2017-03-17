/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:36:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/17 21:27:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			refresh(t_env *e)
{
	printf("ccrefresh\n");

	mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	draw_fractol(e);
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

static void		choose_between_differents_fractols(t_env *e)
{
	if (ft_strcmp(e->choice, "mandelbrot") == 0)
	{
		draw_mandelbrot(e);
	}
	else if (ft_strcmp(e->choice, "julia") == 0)
	{
		draw_julia(e);
	}
	else if (ft_strcmp(e->choice, "burningship") == 0)
	{
		draw_burningship(e);
	}
}

void			draw_fractol(t_env *e)
{
	choose_between_differents_fractols(e);
}