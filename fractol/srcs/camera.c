/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:35:03 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 20:28:12 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_env *e, int x, int y)
{
	e->cam.zm *= 1.1;
	refresh(e);
}

void	zoom_out(t_env *e, int x, int y)
{
	e->cam.zm *= 0.9;
	refresh(e);
}
