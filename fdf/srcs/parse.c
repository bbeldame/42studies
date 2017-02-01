/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/30 19:55:37 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				getsizeof(char *type, char *str)
{
	char	**lns;
	char	**cols;
	int		res;

	if (!(!ft_strcmp(type, "ln") || !ft_strcmp(type, "col")))
		err_found("wrong usage of getsizeof");
	if (!(lns = ft_strsplit(str, '\n')))
		err_found("split failed");
	if (!(cols = ft_strsplit(lns[0], ' ')))
		err_found("split failed");
	if (!ft_strcmp(type, "ln"))
		res = len_of_tab(lns);
	if (!ft_strcmp(type, "col"))
		res = len_of_tab(cols);
	free_splited_str(cols);
	free_splited_str(lns);
	return (res);
}

void			getsize(char *file, t_map **map, int fd)
{
	char	buffer[BUFF_SIZE_FDF + 1];
	char	*str;
	char	*swap;
	int		ret;

	str = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		err_found("open failed");
	while ((ret = read(fd, buffer, BUFF_SIZE_FDF)) > 0)
	{
		if (ret == -1)
			err_found("read failed");
		buffer[ret] = '\0';
		swap = ft_strdup(str);
		str = ft_strjoin(swap, buffer);
		free(swap);
	}
	(*map)->m_ln = getsizeof("ln", str);
	(*map)->m_col = getsizeof("col", str);
	(*map)->str = str;
	if (close(fd) == -1)
		err_found("close failed");
}

int				*parseline(char *str, int m_col)
{
	char	**tab;
	int		*ln;
	int		col;
	char	**z;

	if (!(tab = ft_strsplit(str, ' ')))
		err_found("split failed");
	ln = (int *)semalloc(sizeof(int) * len_of_tab(tab));
	if (len_of_tab(tab) != m_col)
		err_found("lines are not of the same length");
	col = 0;
	while (col < len_of_tab(tab))
	{
		z = ft_strsplit(tab[col], ',');
		ln[col] = ft_atoi(z[0]);
		free_splited_str(z);
		col++;
	}
	free_splited_str(tab);
	return (ln);
}

t_map			*parse(char *file)
{
	char	*str;
	int		y;
	int		fd;
	t_map	*map;

	map = (t_map *)semalloc(sizeof(t_map));
	getsize(file, &map, 0);
	map->coor = (int **)semalloc(sizeof(int *) * (map->m_ln + 1));
	if ((fd = open(file, O_RDONLY)) == -1)
		err_found("open failed");
	y = 0;
	while (get_next_line(fd, &str))
	{
		map->coor[y] = parseline(str, map->m_col);
		y++;
	}
	map->coor[y] = NULL;
	if (close(fd) == -1)
		err_found("close failed");
	return (map);
}

t_env			*initenv(char *file)
{
	t_env	*e;

	e = (t_env *)semalloc(sizeof(t_env));
	e->map = parse(file);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fil de fer");
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img = mlx_get_data_addr(e->img_ptr, &e->cimg.bpp, &e->cimg.sl,
		&e->cimg.e);
	e->cam = NULL;
	mlx_key_hook(e->win, key_hook, e);
	displaytest(e->map);
	return (e);
}
