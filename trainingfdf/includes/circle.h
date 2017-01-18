/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:08:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CIRCLE_H_
# define _CIRCLE_H_

# include "fdf.h"

typedef struct		s_f_circle
{
	int					x;
	int					y;
	int					r;
	int					color;
}									t_f_circle;

void prnt_circle(t_env *env, t_f_circle *cr);
t_f_circle *init_circle(int x, int y, int r, int color);

#endif
