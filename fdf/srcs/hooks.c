/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/05 18:07:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int		refresh(t_env *e)
{
	static int color = 0;
	static int colors[6] = COLORS;

	mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (e->keys.key_e)
		epileptic(e);
	if (e->keys.key_w)
	{
		color++;
		if (color > 5)
			color = 0;
		e->map->ln.color = colors[color];
	}
	if (e->keys.key_pu || (e->keys.key_pd && e->cam.zm > 0.4)
		|| e->keys.key_left || e->keys.key_right
		|| e->keys.key_down || e->keys.key_up
		|| e->keys.key_a || e->keys.key_d)
		rotation_zoom(e);
	if (e->cam.zm > 0.4)
		draw_fdf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (1);
}

void	rot_keyhook(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
		e->keys.key_right = 1;
	if (keycode == KEY_LEFT)
		e->keys.key_left = 1;
	if (keycode == KEY_DOWN)
		e->keys.key_down = 1;
	if (keycode == KEY_UP)
		e->keys.key_up = 1;
	if (keycode == KEY_A)
		e->keys.key_a = 1;
	if (keycode == KEY_D)
		e->keys.key_d = 1;
}

int		keypress_hook(int keycode, t_env *e)
{
	if (keycode == KEY_PU || keycode == KEY_PD)
		zoom_img(e, keycode, 1);
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_F16)
		e->map->ln.color = C_BLUE;
	if (keycode == KEY_F17)
		e->map->ln.color = C_GREEN;
	if (keycode == KEY_F18)
		e->map->ln.color = C_RED;
	if (keycode == KEY_F19)
		e->map->ln.color = C_WHITE;
	if (keycode == KEY_SB)
		e->keys.key_e = 1;
	if (keycode == KEY_W)
		e->keys.key_w = 1;
	rot_keyhook(keycode, e);
	return (0);
}

int		keyrel_hook(int keycode, t_env *e)
{
	if (keycode == KEY_PU || keycode == KEY_PD)
		zoom_img(e, keycode, 0);
	if (keycode == KEY_SB)
		e->keys.key_e = 0;
	if (keycode == KEY_RIGHT)
		e->keys.key_right = 0;
	if (keycode == KEY_LEFT)
		e->keys.key_left = 0;
	if (keycode == KEY_DOWN)
		e->keys.key_down = 0;
	if (keycode == KEY_UP)
		e->keys.key_up = 0;
	if (keycode == KEY_A)
		e->keys.key_a = 0;
	if (keycode == KEY_D)
		e->keys.key_d = 0;
	if (keycode == KEY_W)
		e->keys.key_w = 0;
	return (0);
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
	return (new);
}
