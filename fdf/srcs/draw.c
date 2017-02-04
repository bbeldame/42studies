/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/03 20:39:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		put_pxl(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->cimg.bpp / 8) + (y * e->cimg.sl);
		e->img[pos] = color % 256;
		e->img[pos + 1] = (color >> 8) % 256;
		e->img[pos + 2] = (color >> 16) % 256;
	}
}

void		mlx_fill_image(t_env *e, int color)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH && (y = -1) < 0)
		while (++y < HEIGHT)
			put_pxl(e, x, y, color);
}

void rot_z(t_env *e, int angle)
{
	int y;
	int x;
	DF	rangle;
	DF	tmp;

	rangle = angle * 0.0174533;
	y = 0;
	while (e->map->coor[y])
	{
		x = 0;
		while (x < e->map->m_col)
		{
			tmp = PT.x;
			PT.x = cos(rangle) * PT.x - sin(rangle) * PT.y;
			PT.y = sin(rangle) * tmp + cos(rangle) * PT.y;
			x++;
		}
		y++;
	}
}

void rot_x(t_env *e, int angle)
{
	int y;
	int x;
	DF	rangle;
	DF	tmp;

	rangle = angle * 0.0174533;
	y = 0;
	while (e->map->coor[y])
	{
		x = 0;
		while (x < e->map->m_col)
		{
			tmp = PT.y;
			PT.y = cos(rangle) * PT.y - sin(rangle) * PT.z;
			PT.z = sin(rangle) * tmp + cos(rangle) * PT.z;
			x++;
		}
		y++;
	}
}

void		draw_fdf(t_env *e)
{
	int y;
	int x;

	y = 0;
	while (e->map->coor[y])
	{
		x = 0;
		while (x < e->map->m_col)
		{
			put_pxl(e, e->cam.zm * PT.x + WIDTH / 2, e->cam.zm * PT.y + HEIGHT / 2, C_WHITE);
			x++;
		}
		y++;
	}
}
