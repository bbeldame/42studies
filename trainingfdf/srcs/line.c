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

void prnt_line_h(t_env *env, t_f_line *ln)
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

void prnt_line_v(t_env *env, t_f_line *ln)
{
	int y;

	y = ln->y1;
	while (y<=ln->y2)
	{
		mlx_pixel_put(env->mlx, env->win,
			ln->x1+((ln->x2-ln->x1)*(y-ln->y1))/(ln->y2-ln->y1),
			y,
			ln->color);
		y++;
	}
}

int line_swap(t_f_line *ln) {
	ft_swap(&ln->x1, &ln->x2);
	ft_swap(&ln->y1, &ln->y2);

	return (1);
}

void prnt_line(t_env *env, t_f_line *ln)
{
	int swaped;

	swaped = 0;
	if (ln->x1 == ln->x2 && ln->y1 == ln->y2)
	{
		mlx_pixel_put(env->mlx, env->win, ln->x1, ln->y1, ln->color);
		return ;
	}
	if (ln->x1 > ln->x2)
		swaped = line_swap(ln);
	if ((ln->x2 - ln->x1) >= (ln->y2 - ln->y1))
		prnt_line_h(env, ln);
	else
		prnt_line_v(env, ln);
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