/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:08:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SQUARE_H_
# define _SQUARE_H_

# include "fdf.h"

typedef struct		s_f_square
{
	int					x;
	int					y;
	int					size;
	int					color;
	int					full;
}									t_f_square;

void prnt_full_square(t_env *env, t_f_square *sq);
t_f_square *init_square(int size, int color, int full);

#endif
