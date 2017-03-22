/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:17:06 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 20:30:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		choice_to_int(char *choice)
{
	if (ft_strcmp(choice, "mandelbrot") == 0)
	{
		return (MANDELBROT);
	}
	else if (ft_strcmp(choice, "julia") == 0)
	{
		return (JULIA);
	}
	else if (ft_strcmp(choice, "burningship") == 0)
	{
		return (BURNINGSHIP);
	}
}

static t_env	*initenv(char *choice)
{
	t_env	*e;

	e = (t_env *)semalloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->stt.max_iter = MAX_ITER_DEF;
	e->stt.choice = choice_to_int(choice);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAMEWIN);
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img = mlx_get_data_addr(e->img_ptr, &e->cimg.bpp, &e->cimg.sl,
		&e->cimg.e);
	e->cam.zm = ZOOM_DEF;
	e->stt.pause = 0;
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	return (e);
}

int				main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2 || !(ft_strcmp(av[1], "mandelbrot") == 0
		|| ft_strcmp(av[1], "julia") == 0
		|| ft_strcmp(av[1], "burningship") == 0))
		err_found("usage : fractol [mandelbrot, julia, burningship]");
	e = initenv(av[1]);
	refresh(e);
	mlx_loop(e->mlx);
	return (1);
}
