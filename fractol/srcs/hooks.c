/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:58:27 by bbeldame          #+#    #+#             */
/*   Updated: 2017/06/05 20:25:06 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reset(t_env *e)
{
	e->cam.zm = ZOOM_DEF;
	e->cam.minx = MIN_RANGE_DEF;
	e->cam.maxx = MAX_RANGE_DEF;
	e->cam.miny = MIN_RANGE_DEF;
	e->cam.maxy = MAX_RANGE_DEF;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_PLUS)
		e->stt.max_iter += 3;
	if (keycode == KEY_MINUS)
		e->stt.max_iter -= (e->stt.max_iter > 6) ? 3 : 0;
	if (keycode == KEY_PU)
		zoom_in(e, H / 2, W / 2);
	if (keycode == KEY_PD)
		zoom_out(e, H / 2, W / 2);
	if (keycode == KEY_SB)
		e->stt.pause = (e->stt.pause) ? 0 : 1;
	if (keycode == KEY_R)
		reset(e);
	refresh(e);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == BUTTON_LEFT_CLICK || button == BUTTON_SCROLL_UP)
		zoom_in(e, x, y);
	else if (button == BUTTON_RIGHT_CLICK || button == BUTTON_SCROLL_DOWN)
		zoom_out(e, x, y);
	return (1);
}

int		mouse_position(int x, int y, t_env *e)
{
	if (!e->stt.pause)
	{
		e->cam.coor_x = x;
		e->cam.coor_y = y;
		refresh(e);
	}
	return (1);
}
