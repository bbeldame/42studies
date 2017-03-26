/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:36:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/26 18:17:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		choose_between_differents_fractols(t_env *e)
{
	if (e->stt.choice == MANDELBROT)
		draw_mandelbrot(e, 0, 0);
	else if (e->stt.choice == JULIA)
		draw_julia(e, 0, 0);
	else if (e->stt.choice == BURNINGSHIP)
		draw_burningship(e, 0, 0);
}

void			refresh(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, W, H);
	choose_between_differents_fractols(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
}
