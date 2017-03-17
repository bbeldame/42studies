/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:33:01 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/17 21:27:34 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void        draw_mandelbrot(t_env *e)
{
    printf("cc\n");

    put_pxl(e, 50, 50, C_BLUE);
    put_pxl(e, 50, 51, C_BLUE);
    put_pxl(e, 50, 52, C_BLUE);
    put_pxl(e, 51, 50, C_BLUE);
    put_pxl(e, 51, 51, C_BLUE);
    put_pxl(e, 51, 52, C_BLUE);
    put_pxl(e, 52, 50, C_BLUE);
    put_pxl(e, 52, 51, C_BLUE);
    put_pxl(e, 52, 52, C_BLUE);
}