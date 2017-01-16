/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:07:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 20:08:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LINE_H_
# define _LINE_H_

# include "fdf.h"

typedef struct		s_f_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color;
}									t_f_line;

void prnt_line(t_env *env, t_f_line *ln);
t_f_line *init_line(int color);

#endif
