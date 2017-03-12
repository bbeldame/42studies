/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:06:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/05 18:12:25 by bbeldame         ###   ########.fr       */
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
# define BWMODE 0

# define BUFF_SIZE_FDF 250001

# define HEIGHT 1313
# define WIDTH 2300
# define HEIGHTDIV2 656.5
# define WIDTHDIV2 1150

# define NAMEFDF "Fil de fer"

# define ZOOM_DEF 30
# define X_DEF 40
# define Y_DEF -15
# define Z_DEF 0
# define Z_REDUCE_DEF 5

# define DEGTORAD 0.0174533

# define COLORS {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF, 0x00FF00}

# define PT e->map->coor[y][x]
# define PTNEXTX e->map->coor[y][x + 1]
# define PTNEXTY e->map->coor[y + 1][x]

# define C_WHITE 0xFFFFFF
# define C_BLUE 0x248A8A
# define C_GREEN 0xC9FA58
# define C_YELLOW 0xF9E555
# define C_ORANGE 0xFAAC38
# define C_RED 0xF2572A
# define C_BLACK 0x000000
# define C_PURPLE 0x750057
# define C_PINK 0xDD516B
# define C_GGREEN 0x00FF00

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
# define KEY_E 14
# define KEY_S 1
# define KEY_D 2
# define KEY_PU 116
# define KEY_PD 121
# define KEY_SB 49
# define KEY_0 82
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92

# define DF long double

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L << 0)
# define KEYRELEVENT 3
# define KEYRELMASK (1L << 1)

typedef struct			s_point
{
	DF					x;
	DF					y;
	DF					z;
}						t_point;

typedef struct			s_cam
{
	DF					zm;
	int					colorfdf;
	int					colorbg;
	int					x;
	int					y;
}						t_cam;

typedef struct			s_keys
{
	int					key_pu;
	int					key_pd;
	int					key_e;
	int					key_left;
	int					key_right;
	int					key_up;
	int					key_down;
	int					key_a;
	int					key_d;
	int					key_w;
	int					key_1;
	int					key_2;
	int					key_3;
	int					key_4;
	int					key_6;
	int					key_7;
	int					key_8;
	int					key_9;
}						t_keys;

typedef struct			s_cimg
{
	int					bpp;
	int					sl;
	int					e;
}						t_cimg;

typedef struct			s_f_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					color;
}						t_f_line;

typedef	struct			s_map
{
	int					m_col;
	int					m_ln;
	t_f_line			ln;
	t_point				**coor;
}						t_map;

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img_ptr;
	char				*img;
	t_cimg				cimg;
	t_map				*map;
	t_cam				cam;
	t_keys				keys;
	int					parsed;
	char				*file;
}						t_env;

t_env					*initenv(char *file);
int						len_of_tab(char **tab);
void					displaytest(t_map *map);
void					err_found(char *str);
void					mlx_fill_image(t_env *e, int color);
void					put_pxl(t_env *e, int x, int y, int color);
int						keypress_hook(int keycode, t_env *e);
t_f_line				*init_line(int color);
void					draw_fdf(t_env *e);
void					free_splited_str(char **str);
void					displaytest(t_map *map);
void					*semalloc(size_t size);
t_f_line				*init_line(int color);
void					prnt_line(t_env *e, t_f_line ln);
int						refresh(t_env *e);
int						keyrel_hook(int keycode, t_env *e);
t_keys					init_keys();
void					rot_z(t_env *e, DF angle);
void					rot_x(t_env *e, DF angle);
void					rot_y(t_env *e, DF angle);
void					epileptic(t_env *e);
void					color_changer(t_env *e);
void					rotation_zoom(t_env *e);
void					zoom_img(t_env *e, int keycode, int activation);
void					color_changer(t_env *e);
void					move_cam(t_env *e, int x, int y);
void					move_cam_keyhook(t_env *e);
int						expose_hook(t_env *e);

#endif
