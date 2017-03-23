/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:58:27 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/23 20:30:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_PLUS)
		e->stt.max_iter += 3;
	if (keycode == KEY_MINUS)
		e->stt.max_iter -= (e->stt.max_iter > 6) ? 3 : 0;
	refresh(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("button is %d, x is %d, y is %d\n", button, x, y);
	if (button == BUTTON_LEFT_CLICK || button == BUTTON_SCROLL_UP)
	{
		zoom_in(e, x, y);
	}
	else if (button == BUTTON_RIGHT_CLICK || button == BUTTON_SCROLL_DOWN)
	{
		zoom_out(e, x, y);
	}
}
