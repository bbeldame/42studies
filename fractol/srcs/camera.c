/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:35:03 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/26 19:35:10 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static DL	ft_map(DL x, DL size, DL min, DL max)
{
	return ((x / size) * (max - min) + min);
}

void		zoom_in(t_env *e, int x, int y)
{
	DL xlen;
	DL ylen;
	DL temp;

	temp = (e->cam.maxx - e->cam.minx) / 2;
	xlen = ft_map(x, W, e->cam.minx, e->cam.maxx);
	ylen = ft_map(y, H, e->cam.miny, e->cam.maxy);
	e->cam.minx = (xlen - temp);
	e->cam.maxx = (xlen + temp);
	temp = (e->cam.maxy - e->cam.miny) / 2;
	e->cam.miny = (ylen - temp);
	e->cam.maxy = (ylen + temp);
	e->cam.zm *= 1.1;
	refresh(e);
}

void		zoom_out(t_env *e, int x, int y)
{
	DL xlen;
	DL ylen;
	DL temp;

	temp = (e->cam.maxx - e->cam.minx) / 2;
	xlen = ft_map(x, W, e->cam.minx, e->cam.maxx);
	ylen = ft_map(y, H, e->cam.miny, e->cam.maxy);
	e->cam.minx = (xlen - temp);
	e->cam.maxx = (xlen + temp);
	temp = (e->cam.maxy - e->cam.miny) / 2;
	e->cam.miny = (ylen - temp);
	e->cam.maxy = (ylen + temp);
	e->cam.zm *= 0.9;
	refresh(e);
}
