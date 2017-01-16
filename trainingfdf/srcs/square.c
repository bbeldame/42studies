/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:06:52 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:06:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square.h"

void prnt_full_square(t_env *env, t_f_square *sq)
{
	int i;
	int j;

	j = sq->y;
	while (j <= sq->size + sq->y)
	{
		i = sq->x;
		while (i <= sq->size + sq->x)
		{
			mlx_pixel_put(env->mlx, env->win, i, j, sq->color);
			i++;
		}
		j++;
	}
}

t_f_square *init_square(int size, int color, int full)
{
	t_f_square *sq;

	if (!(sq = (t_f_square*)malloc(sizeof(t_f_square))))
		return (NULL);
	sq->x = 0;
	sq->y = 0;
	sq->size = size;
	sq->color = color;
	sq->full = full;
	return (sq);
}
