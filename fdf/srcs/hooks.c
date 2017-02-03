/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/03 20:38:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_img(t_env **e, int keycode)
{
	if (keycode == KEY_PU)
		(*e)->cam.zm += 1;
	if (keycode == KEY_PD)
		if ((*e)->cam.zm > 1)
			(*e)->cam.zm -= 1;
}

int		key_hook(int keycode, t_env *e)
{
	printf("key = %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	mlx_fill_image(e, C_WHITE);
	if (keycode == KEY_PU || keycode == KEY_PD)
		zoom_img(&e, keycode);
	draw_fdf(e);
	return (0);
}
