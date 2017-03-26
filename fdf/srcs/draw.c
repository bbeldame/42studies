/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/26 20:00:38 by bbeldame         ###   ########.fr       */
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
	if (BWMODE)
		while (++x < WIDTH && (y = -1) < 0)
			while (++y < HEIGHT)
				put_pxl(e, x, y, color);
}

void		draw_horizontal(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (e->map->coor[y])
	{
		x = 0;
		while (x < e->map->m_col - 1)
		{
			e->map->ln.x1 = e->cam.zm * PT.x + WIDTHDIV2 + e->cam.x;
			e->map->ln.y1 = e->cam.zm * PT.y + HEIGHTDIV2 + e->cam.y;
			e->map->ln.x2 = e->cam.zm * PTNEXTX.x + WIDTHDIV2 + e->cam.x;
			e->map->ln.y2 = e->cam.zm * PTNEXTX.y + HEIGHTDIV2 + e->cam.y;
			prnt_line(e, e->map->ln);
			x++;
		}
		y++;
	}
}

void		draw_vertical(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < e->map->m_col)
	{
		y = 0;
		while (e->map->coor[y + 1])
		{
			e->map->ln.x1 = e->cam.zm * PT.x + WIDTHDIV2 + e->cam.x;
			e->map->ln.y1 = e->cam.zm * PT.y + HEIGHTDIV2 + e->cam.y;
			e->map->ln.x2 = e->cam.zm * PTNEXTY.x + WIDTHDIV2 + e->cam.x;
			e->map->ln.y2 = e->cam.zm * PTNEXTY.y + HEIGHTDIV2 + e->cam.y;
			prnt_line(e, e->map->ln);
			y++;
		}
		x++;
	}
}

void		draw_fdf(t_env *e)
{
	draw_horizontal(e);
	draw_vertical(e);
}
