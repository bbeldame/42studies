/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:06:52 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:06:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/line.h"

void prnt_line(t_env *env, t_f_line *ln)
{
	int x;

	x = ln->x1;
	while (x<=ln->x2)
	{
		mlx_pixel_put(env->mlx, env->win,
			x,
			ln->y1+((ln->y2-ln->y1)*(x-ln->x1))/(ln->x2-ln->x1),
			ln->color);
		x++;
	}
}

t_f_line *init_line(int color)
{
	t_f_line *line;

	if (!(line = (t_f_line*)malloc(sizeof(t_f_line))))
		return (NULL);
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 20;
	line->y2 = 20;
	line->color = color;
	return (line);
}
