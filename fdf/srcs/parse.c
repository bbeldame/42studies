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

void		displaytest(t_map *map)
{
	int		i;
	int		j;

	ft_putstr("------------------------DEBUT-----------------------------\n");
	i = 0;
	while (i <= map->m_ln)
	{
		j = 0;
		while (j <= map->m_col)
		{
			ft_putnbr(map->coor[i][j++]);
			ft_putstr(", ");
		}
		i++;
		ft_putstr("\n");
	}
	ft_putstr("-------------------------FIN-------------------------------\n");
}

void			getsize(char *file, int *col, int *ln)
{
	int fd;
	char buffer[BUFF_SIZE_FDF + 1];
	char *str;
	int ret;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit (err_found("open failed"));
	ft_putstr("hihi\n");
	while ((ret = read(fd, buffer, BUFF_SIZE_FDF)) > 0)
	{
		ft_putstr("cc\n");
		if (ret == -1)
			exit (err_found("read failed"));
		buffer[ret] = '\0';
		ft_putstr("wtfcaca\n");
		str = ft_strjoin(str, buffer);
		ft_putstr("wtf\n");
	}
	ft_putstr("hihi2\n");
	*ln = len_of_tab(ft_strsplit(str, '\n'));
	printf("Nombre de lignes : %d\n", *ln);
	*col = len_of_tab(ft_strsplit(ft_strsplit(str, '\n')[0], ' '));
	printf("Nombre de colonnes : %d\n", *col);
	if (close(fd) == -1)
		exit (err_found("close failed"));
}

int		*parseline(char *str, int m_col)
{
	char	**tab;
	int		*ln;
	int		col;
	char	**z;

	ft_putstr("Coucou\n");
	if (!(tab = ft_strsplit(str, ' ')))
		exit (err_found("parse.c:46 not enough memory"));
	if (!(ln = (int *)malloc(sizeof(int) * (len_of_tab(tab)))))
		exit (err_found("parse.c:48 not enough memory"));
	if (len_of_tab(tab) != m_col)
		exit (err_found("parse.c:70 lines are not of the same length"));
	col = 0;
	while (col < len_of_tab(tab))
	{
		z = ft_strsplit(tab[col], ',');
		ln[col] = ft_atoi(z[0]);
		free_splited_str(z);
		col++;
	}
	ft_memdel((void **)&tab);
	return (ln);
}

t_map			*parse(char *file)
{
	char	*str;
	int		y;
	int		fd;
	t_map *map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		exit (err_found("parse.c:90 not enough memory"));
	getsize(file, &map->m_col, &map->m_ln);
	if (!(map->coor = (int **)malloc(sizeof(int *) * (map->m_ln + 1))))
		exit (err_found("parse.c:93 not enough memory"));
	if ((fd = open(file, O_RDONLY)) == -1)
		exit (err_found("open failed"));
	y = 0;
	while (get_next_line(fd, &str))
	{
		map->coor[y] = parseline(str, map->m_col);
		y++;
	}
	map->coor[y] = NULL;
	if (close(fd) == -1)
		exit (err_found("close failed"));
	return (map);
}

t_env		*initenv(char *file)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->map = parse(file);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fil de fer");
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img = mlx_get_data_addr(e->img_ptr, &e->cimg.bpp, &e->cimg.sl, &e->cimg.e);
	e->cam = NULL;
	mlx_key_hook(e->win, key_hook, e);
	displaytest(e->map);
	return (e);
}
