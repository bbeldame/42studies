/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/03 20:39:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_changer(t_env *e)
{
	static int color = 0;
	static int colors[6] = COLORS;
	static int timer = 0;

	if ((++timer % 5) == 0)
	{
		color++;
		if (color > 5)
			color = 0;
		e->map->ln.color = colors[color];
	}
	if (timer == 60)
		timer = 0;
}

void	move_cam(t_env *e, int x, int y)
{
	e->cam.x = x;
	e->cam.y = y;
}

void	move_cam_keyhook(t_env *e)
{
	if (e->keys.key_1)
		move_cam(e, e->cam.x - 10, e->cam.y + 10);
	if (e->keys.key_2)
		move_cam(e, e->cam.x, e->cam.y + 15);
	if (e->keys.key_3)
		move_cam(e, e->cam.x + 10, e->cam.y + 10);
	if (e->keys.key_4)
		move_cam(e, e->cam.x - 15, e->cam.y);
	if (e->keys.key_6)
		move_cam(e, e->cam.x + 15, e->cam.y);
	if (e->keys.key_7)
		move_cam(e, e->cam.x - 10, e->cam.y - 10);
	if (e->keys.key_8)
		move_cam(e, e->cam.x, e->cam.y - 15);
	if (e->keys.key_9)
		move_cam(e, e->cam.x + 10, e->cam.y - 10);
}
