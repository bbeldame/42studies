/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:36:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/23 21:34:43 by bbeldame         ###   ########.fr       */
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
	e->img_ptr = mlx_new_image(e->mlx, BASE_WIDTH, BASE_HEIGHT);
	choose_between_differents_fractols(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
}

void			put_pxl(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < BASE_WIDTH && y >= 0 && y < BASE_HEIGHT)
	{
		pos = (x * e->cimg.bpp / 8) + (y * e->cimg.sl);
		e->img[pos] = color % 256;
		e->img[pos + 1] = (color >> 8) % 256;
		e->img[pos + 2] = (color >> 16) % 256;
	}
}

DL				get_coor(DL n, DL coor, t_env *e)
{
	DL	point;
	DL preser;

	preser = ZOOM_WIDTH;
	point = ft_map(coor, BASE_WIDTH, MIN_RANGE / ZOOM, MAX_RANGE / ZOOM);
	e->cam.min = point - (preser / 2);
	e->cam.max = preser / 2 + point;
	DL start2 = MIN_RANGE / ZOOM;
	DL stop2 = MAX_RANGE / ZOOM;

	return (((n-e->cam.min)/(e->cam.max-e->cam.min))*(stop2-start2)+start2);
}