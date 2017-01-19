/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:06:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/16 19:39:23 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "get_next_line.h"

# define BASE_COLOR "0x0000FF"

typedef struct		s_pt
{
	int					z;
	char				*color;
}									t_pt;

typedef struct		s_env
{
	void				*win;
	void				*mlx;
	t_pt				**map;
}					t_env;

t_env		*initenv(int fd);

#endif
