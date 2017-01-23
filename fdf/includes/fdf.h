/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:06:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:38:49 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "get_next_line.h"

# define BASE_COLOR "0x0000FF"

typedef struct			s_map
{
	int					z;
	char				*color;
}						t_map;

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	t_map				***map;
}						t_env;

t_env					*initenv(int fd);
int						len_of_tab(char **tab);
int						cpymap(t_map ****new, t_map ***curr, int len);
char					*getcolor(char *str);
void					*clrmap(t_map ****curr);
void					displaytest(t_map ***map);
int						err_found(char *str);

#endif
