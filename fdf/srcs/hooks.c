/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:39:16 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode, t_env *e)
{
	printf("key = %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_F16)
		mlx_fill_image(e, C_RED);
	if (keycode == KEY_F17)
		mlx_fill_image(e, C_ORANGE);
	if (keycode == KEY_F18)
		mlx_fill_image(e, C_YELLOW);
	if (keycode == KEY_F19)
		mlx_fill_image(e, C_PURPLE);
	draw_fdf(e);
	return (0);
}
