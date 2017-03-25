/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:13:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/25 19:45:55 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define LIMIT 4

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

# define MIN_RANGE_DEF -2
# define MAX_RANGE_DEF 2

# define H 800
# define W 800

# define BASE_COOR_X 400
# define BASE_COOR_Y 400

# define NAMEWIN "Fractol"

# define MAX_ITER_DEF 30
# define ZOOM_DEF 1
# define ZOOM e->cam.zm
# define MAXITER e->stt.max_iter

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
# define KEY_PLUS 69
# define KEY_MINUS 78
# define BUTTON_LEFT_CLICK 1
# define BUTTON_RIGHT_CLICK 2
# define BUTTON_SCROLL_UP 5
# define BUTTON_SCROLL_DOWN 987987 // NE SAIT PAS ENCORE

# define DL long double

typedef struct			s_cam
{
	DL					zm;
	int					x;
	int					y;
	DL					minx;
	DL					maxx;
	DL					miny;
	DL					maxy;
	int					coor_x;
	int					coor_y;
}						t_cam;

typedef struct			s_settings
{
	int					pause;
	int					max_iter;
	int					choice;
}						t_settings;

typedef struct			s_cimg
{
	int					bpp;
	int					sl;
	int					e;
}						t_cimg;

typedef	struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img_ptr;
	char				*img;
	t_settings			stt;
	t_cimg				cimg;
	t_cam				cam;
}						t_env;

/*
**						Utils
*/
void					err_found(char *str);
void					*semalloc(size_t size);
int						len_of_tab(char **tab);
void					free_splited_str(char **str);
DL						ft_map(DL x, DL size, DL min, DL max);

/*
**						Hooks
*/
int						key_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						mouse_position(int x, int y, t_env *e);

/*
**						Draw
*/
void					refresh(t_env *e);
void					put_pxl(t_env *e, int x, int y, int color);
DL						get_coor(DL x, DL size, t_env *e);

/*
**						Mandelbrot
*/
void					draw_mandelbrot(t_env *e, int x, int y);

/*
**						Julia
*/
void					draw_julia(t_env *e, int x, int y);

/*
**						Burningship
*/
void					draw_burningship(t_env *e, int x, int y);

/*
**						Camera
*/
void					zoom_in(t_env *e, int x, int y);
void					zoom_out(t_env *e, int x, int y);

#endif
