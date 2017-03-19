/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:55:00 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/19 19:06:19 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void        draw_burningship(t_env *e, int x, int y)
{
    put_pxl(e, 50, 50, 0xFFFFFF);
    refresh(e);
}