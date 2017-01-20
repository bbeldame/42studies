/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/19 20:05:43 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 		displaytest(t_env *e)
{
	ft_putstr("ok\n");
	ft_putstr(e->map[0][0]->color);
	ft_putstr("ok\n");
}

t_map		***newline(t_map ***curr)
{
	t_map ***new;
	int		i;

	if (!curr)
	{
		if (!(new = (t_map ***)malloc(sizeof(t_map **))))
			return (NULL);
		return (new);
	}
	ft_putstr("klklk\n");
	i = 0;
	while (curr[i])
		i++;
	ft_putnbr(i);
	if (!(new = (t_map ***)malloc(sizeof(t_map **) * i)))
		return (NULL);
	new = cpymap(new, curr, i);
	ft_putstr("cpydone\n");
	curr = clrmap(&curr);
	ft_putstr("clrdone\n");
	new[i] = NULL;
	return (new);
}

t_map		**parseline(char *str)
{
	char 	**tab;
	int		col;
	t_map **ln;

	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(ln = (t_map **)malloc(sizeof(t_map *) * (len_of_tab(tab)))))
		return (NULL);
	col = 0;
	ft_putstr("koko\n");
	while (col < len_of_tab(tab))
	{
		if (!(ln[col] = (t_map *)malloc(sizeof(t_map))))
			return (NULL);
		ln[col]->z = ft_atoi(ft_strsplit(tab[col], ',')[0]);
		ln[col]->color = getcolor(ft_strsplit(tab[col], ',')[1]);
		col++;
	}
	ft_putstr("lafesse\n");
	ln[col] = NULL;
	return (ln);
}

t_env		*initenv(int fd)
{
	char	*str;
	int		y;
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->map = NULL;
	y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		ft_putstr("okok\n");
		e->map = newline(e->map);
		e->map[y + 1] = NULL;
		ft_putstr("coolcool\n");
		e->map[y] = parseline(str);
		ft_putstr("les bons gateaux\n");
		ft_putstr(e->map[y][0]->color);
		ft_putstr("blabla\n");
		y++;
	}
	ft_putstr(e->map[--y][0]->color);
	e->map = newline(e->map);
	e->map[y] = NULL;
	ft_putstr("wot\n");
//	ft_putstr(e->map[0][0].color);
	displaytest(e);
	return (e);
}
