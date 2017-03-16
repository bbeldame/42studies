/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:06:52 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/16 20:16:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Bresenhams Algorithm
*/

static int	inverse_if_needed(t_f_line *ln)
{
	int	inversed;

	inversed = 0;
	if (abs(ln->x1 - ln->x2) < abs(ln->y1 - ln->y2))
	{
		ft_swap(&(ln->x1), &(ln->y1));
		ft_swap(&(ln->x2), &(ln->y2));
		inversed = 1;
	}
	if (ln->x1 > ln->x2)
	{
		ft_swap(&(ln->x1), &(ln->x2));
		ft_swap(&(ln->y1), &(ln->y2));
	}
	return (inversed);
}

static void	draw_line(t_env *e, t_f_line ln, int inversed, DF dx)
{
	DF	x;
	DF	y;
	DF	derror2;
	DF	error2;

	x = ln.x1;
	y = ln.y1;
	derror2 = abs(ln.y2 - ln.y1) * 2;
	error2 = 0;
	while (x <= ln.x2)
	{
		if (inversed)
			put_pxl(e, y, x, ln.color);
		else
			put_pxl(e, x, y, ln.color);
		error2 += derror2;
		if (error2 > dx)
		{
			y += (ln.y2 > ln.y1 ? 1 : -1);
			error2 -= dx * 2;
		}
		x++;
	}
}

void		prnt_line(t_env *e, t_f_line ln)
{
	int inversed;
	DF	dx;

	inversed = inverse_if_needed(&ln);
	dx = ln.x2 - ln.x1;
	draw_line(e, ln, inversed, dx);
}
