/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:06:52 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:06:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circle.h"

void prnt_circle(t_env *env, t_f_circle *cr)
{
	float a;

	a = 0;
	while (a <= 360)
	{
		mlx_pixel_put(env->mlx, env->win,
			cr->x + cr->r * cos(a),
			cr->y + cr->r * sin(a),
			cr->color
		);
		a = a + (2 * M_PI / (8 * cr->r));
	}
}

t_f_circle *init_circle(int x, int y, int r, int color)
{
	t_f_circle *circle;

	if (!(circle = (t_f_circle*)malloc(sizeof(t_f_circle))))
		return (NULL);
	circle->x = x;
	circle->y = y;
	circle->r = r;
	circle->color = color;
	return (circle);
}
