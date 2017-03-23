/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:35:03 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/23 20:29:55 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_env *e, int x, int y)
{
	e->cam.zm *= 1.1;
	e->cam.coor_x = x;
	e->cam.coor_y = y;
	refresh(e);
}

void	zoom_out(t_env *e, int x, int y)
{
	e->cam.zm *= 0.9;
	e->cam.coor_x = x;
	e->cam.coor_y = y;
	refresh(e);
}
