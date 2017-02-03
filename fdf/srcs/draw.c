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

int			centerit(t_env *e, int x, int height)
{
	if (height)
		return ((x - e->map->m_ln / 2) * ZMHEIGHT);
	return ((x - e->map->m_col / 2) * ZMWIDTH);
}

void		makeline(t_env *e, int i, int j)
{
	t_f_line *line;

	line = NULL;
	if (e->map->coor[i + 1])
	{
		line = init_line(C_BLACK);
		line->x1 = centerit(e, j, 0);
		line->y1 = centerit(e, i, 1);
		line->x2 = centerit(e, j, 0);
		line->y2 = centerit(e, i + 1, 1);
		prnt_line(e, line);
	}
	if (j + 1 < e->map->m_col)
	{
		if (line)
			free(line);
		line = init_line(C_BLACK);
		line->x1 = centerit(e, j, 0);
		line->y1 = centerit(e, i, 1);
		line->x2 = centerit(e, j + 1, 0);
		line->y2 = centerit(e, i, 1);
		prnt_line(e, line);
	}
	if (line)
		free(line);
}

void		draw_fdf(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (e->map->coor[i])
	{
		j = 0;
		while (j < e->map->m_col)
		{
			makeline(e, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
}
