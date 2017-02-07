/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roation.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/05 18:07:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_z(t_env *e, DF angle)
{
	int y;
	int x;
	DF	rangle;
	DF	tmp;

	rangle = angle * DEGTORAD;
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

void	rot_x(t_env *e, DF angle)
{
	int y;
	int x;
	DF	rangle;
	DF	tmp;

	rangle = angle * DEGTORAD;
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

void	rot_y(t_env *e, DF angle)
{
	int y;
	int x;
	DF	rangle;
	DF	tmp;

	rangle = angle * DEGTORAD;
	y = 0;
	while (e->map->coor[y])
	{
		x = 0;
		while (x < e->map->m_col)
		{
			tmp = PT.x;
			PT.x = cos(rangle) * PT.x + sin(rangle) * PT.z;
			PT.z = sin(rangle) * -tmp + cos(rangle) * PT.z;
			x++;
		}
		y++;
	}
}
