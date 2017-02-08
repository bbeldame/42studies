/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/03 20:39:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	epileptic(t_env *e)
{
	static int epileptic = 0;
	static int timer = 0;

	timer++;
	if (epileptic)
	{
		epileptic = 0;
		mlx_fill_image(e, C_BLACK);
	}
	else
	{
		epileptic = 1;
		mlx_fill_image(e, C_WHITE);
	}
	rot_y(e, 5);
	rot_x(e, -5);
	color_changer(e);
	if (timer < 60)
		e->cam.x += 20;
	else if (timer < 180)
		e->cam.x -= 20;
	else
		e->cam.x += 20;
	if (timer == 240)
		timer = 0;
}

void	zoom_img(t_env *e, int keycode, int activation)
{
	if (keycode == KEY_PD)
		e->keys.key_pd = activation;
	if (keycode == KEY_PU)
		e->keys.key_pu = activation;
}

void	rotation_zoom(t_env *e)
{
	if (e->keys.key_pu)
		e->cam.zm *= 1.1;
	if (e->keys.key_pd && e->cam.zm > 0.4)
		e->cam.zm /= 1.1;
	if (e->keys.key_left)
		rot_y(e, -5);
	if (e->keys.key_right)
		rot_y(e, 5);
	if (e->keys.key_down)
		rot_x(e, -5);
	if (e->keys.key_up)
		rot_x(e, 5);
	if (e->keys.key_a)
		rot_z(e, -5);
	if (e->keys.key_d)
		rot_z(e, 5);
}

t_keys	init_keys(void)
{
	t_keys new;

	new.key_e = 0;
	new.key_pu = 0;
	new.key_pd = 0;
	new.key_right = 0;
	new.key_left = 0;
	new.key_down = 0;
	new.key_up = 0;
	new.key_a = 0;
	new.key_d = 0;
	new.key_w = 0;
	new.key_1 = 0;
	new.key_2 = 0;
	new.key_3 = 0;
	new.key_4 = 0;
	new.key_6 = 0;
	new.key_7 = 0;
	new.key_8 = 0;
	new.key_9 = 0;
	return (new);
}
