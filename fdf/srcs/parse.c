/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:43:37 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		displaytest(t_map ***map)
{
	int		i;
	int		j;

	ft_putstr("------------------------DEBUT-----------------------------\n");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putnbr(map[i][j++]->z);
			ft_putstr(", ");
		}
		i++;
		ft_putstr("\n");
	}
	ft_putstr("-------------------------FIN-------------------------------\n");
}

t_map		***newline(t_map ***curr)
{
	t_map	***new;
	int		i;

	if (!curr)
	{
		if (!(new = (t_map ***)malloc(sizeof(t_map) * 2)))
			return (NULL);
		new[0] = NULL;
		new[1] = NULL;
		return (new);
	}
	i = 0;
	while (curr[i])
		i++;
	if (!(new = (t_map ***)malloc(sizeof(t_map) * (i + 1))))
		return (NULL);
	if (!cpymap(&new, curr, i))
		return (NULL);
	curr = clrmap(&curr);
	return (new);
}

t_map		**parseline(char *str)
{
	char	**tab;
	int		col;
	t_map	**ln;

	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(ln = (t_map **)malloc(sizeof(t_map) * (len_of_tab(tab) + 1))))
		return (NULL);
	col = 0;
	while (col < len_of_tab(tab))
	{
		if (!(ln[col] = (t_map *)malloc(sizeof(t_map))))
			return (NULL);
		ln[col]->z = ft_atoi(ft_strsplit(tab[col], ',')[0]);
		ln[col]->color = getcolor(ft_strsplit(tab[col], ',')[1]);
		col++;
	}
	ft_memdel((void **)&tab);
	ln[col] = NULL;
	return (ln);
}

t_env		*initenv(int fd)
{
	char	*str;
	int		y;
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->map = NULL;
	y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		e->map = newline(e->map);
		e->map[y] = parseline(str);
		free(str);
		y++;
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fil de fer");
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	displaytest(e->map);
	return (e);
}
