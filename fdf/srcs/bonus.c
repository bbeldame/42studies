/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/03 20:39:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	epileptic(t_env *e)
{
	static int epileptic = 0;

	if (epileptic)
	{
		epileptic = 0;
		mlx_fill_image(e, C_BLACK);
	}
	else
	{
		epileptic = 1;
		mlx_fill_image(e, C_WHITE);
	}
}
