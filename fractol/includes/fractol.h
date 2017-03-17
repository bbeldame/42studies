/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:13:57 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/17 21:22:18 by bbeldame         ###   ########.fr       */
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

# define HEIGHT 600
# define WIDTH 800
# define HEIGHTDIV2 300
# define WIDTHDIV2 400

# define NAMEWIN "Fractol"

# define ZOOM_DEF 30

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

# define DL long double

typedef struct			s_cam
{
	DL					zm;
	int					x;
	int					y;
}						t_cam;

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
	char				*choice;
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

/*
**						Hooks
*/
int						key_hook(int keycode, t_env *e);

/*
**						Draw
*/
void					refresh(t_env *e);
void					put_pxl(t_env *e, int x, int y, int color);
void					draw_fractol(t_env *e);

/*
**						Mandelbrot
*/
void					draw_mandelbrot(t_env *e);

/*
**						Julia
*/
void					draw_julia(t_env *e);

/*
**						Burningship
*/
void					draw_burningship(t_env *e);

#endif
