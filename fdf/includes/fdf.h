/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:06:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/01 20:10:45 by bbeldame         ###   ########.fr       */
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

# define BASE_COLOR "0x000000"

# define BUFF_SIZE_FDF 250001

# define HEIGHT 1313
# define WIDTH 2300

# define C_WHITE 0xFFFFFF
# define C_BLUE 0x248A8A
# define C_GREEN 0xC9FA58
# define C_YELLOW 0xF9E555
# define C_ORANGE 0xFAAC38
# define C_RED 0xF2572A
# define C_BLACK 0x000000
# define C_PURPLE 0x750057
# define C_PINK 0xDD516B

# define KEY_ESC 53
# define KEY_F16 106
# define KEY_F17 64
# define KEY_F18 79
# define KEY_F19 80
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PU 116
# define KEY_PD 121
# define KEY_SB 49

typedef struct			s_cam
{
	int					zoom;
}						t_cam;

typedef struct			s_cimg
{
	int					bpp;
	int					sl;
	int					e;
}						t_cimg;

typedef	struct			s_map
{
	int					m_col;
	int					m_ln;
	int					**coor;
	char				*str;
}						t_map;

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img_ptr;
	char				*img;
	t_cimg				cimg;
	t_map				*map;
	t_cam				*cam;
}						t_env;

typedef struct			s_f_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color;
}						t_f_line;

t_env					*initenv(char *file);
int						len_of_tab(char **tab);
int						cpymap(t_map ****new, t_map ***curr, int len);
char					*getcolor(char *str);
void					*clrmap(t_map ****curr);
void					displaytest(t_map *map);
void					err_found(char *str);
void					mlx_fill_image(t_env *e, int color);
void					put_pxl(t_env *e, int x, int y, int color);
int						key_hook(int keycode, t_env *e);
void					prnt_line(t_env *e, t_f_line *ln);
t_f_line				*init_line(int color);
void					draw_fdf(t_env *e);
void					free_splited_str(char **str);
void					displaytest(t_map *map);
void					*semalloc(size_t size);

#endif
