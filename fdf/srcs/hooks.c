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

int		refresh(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (e->keys.key_e)
		epileptic(e);
	if (e->keys.key_w)
		color_changer(e);
	if (e->keys.key_pu || (e->keys.key_pd && e->cam.zm > 0.4)
		|| e->keys.key_left || e->keys.key_right
		|| e->keys.key_down || e->keys.key_up
		|| e->keys.key_a || e->keys.key_d)
		rotation_zoom(e);
	if (e->keys.key_1 || e->keys.key_2 || e->keys.key_3 || e->keys.key_4 ||
		e->keys.key_6 || e->keys.key_7 || e->keys.key_8 || e->keys.key_9)
		move_cam_keyhook(e);
	if (e->cam.zm > 0.4)
		draw_fdf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (1);
}

void	rot_keyhook(int keycode, t_env *e, int activation)
{
	if (keycode == KEY_RIGHT)
		e->keys.key_right = activation;
	if (keycode == KEY_LEFT)
		e->keys.key_left = activation;
	if (keycode == KEY_DOWN)
		e->keys.key_down = activation;
	if (keycode == KEY_UP)
		e->keys.key_up = activation;
	if (keycode == KEY_A)
		e->keys.key_a = activation;
	if (keycode == KEY_D)
		e->keys.key_d = activation;
}

void	camera_keyhook(int keycode, t_env *e, int activation)
{
	if (keycode == KEY_1)
		e->keys.key_1 = activation;
	if (keycode == KEY_2)
		e->keys.key_2 = activation;
	if (keycode == KEY_3)
		e->keys.key_3 = activation;
	if (keycode == KEY_4)
		e->keys.key_4 = activation;
	if (keycode == KEY_6)
		e->keys.key_6 = activation;
	if (keycode == KEY_7)
		e->keys.key_7 = activation;
	if (keycode == KEY_8)
		e->keys.key_8 = activation;
	if (keycode == KEY_9)
		e->keys.key_9 = activation;
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
	if (keycode == KEY_0)
		move_cam(e, 0, 0);
	rot_keyhook(keycode, e, 1);
	camera_keyhook(keycode, e, 1);
	return (0);
}

int		keyrel_hook(int keycode, t_env *e)
{
	if (keycode == KEY_PU || keycode == KEY_PD)
		zoom_img(e, keycode, 0);
	if (keycode == KEY_SB)
		e->keys.key_e = 0;
	if (keycode == KEY_W)
		e->keys.key_w = 0;
	rot_keyhook(keycode, e, 0);
	camera_keyhook(keycode, e, 0);
	return (0);
}
