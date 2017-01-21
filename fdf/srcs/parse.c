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

void 		displaytest(t_map ***map)
{
	int i;
	int j;

	ft_putstr("--------------------------DEBUT--------------------------------\n");
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
	ft_putstr("---------------------------FIN----------------------------------\n");
}

t_map		***newline(t_map ***curr)
{
	t_map ***new;
	int		i;

	if (!curr)
	{
		if (!(new = (t_map ***)malloc(sizeof(t_map **) * 2)))
			return (NULL);
		new[0] = NULL;
		new[1] = NULL;
		return (new);
	}
	ft_putstr("klklk\n");
	i = 0;
	while (curr[i])
		i++;
	ft_putstr("i avant cpy = ");
	ft_putnbr(i);
	ft_putstr("\n");
	if (!(new = (t_map ***)malloc(sizeof(t_map **) * (i + 1))))
		return (NULL);
	if (!cpymap(&new, curr, i))
		return (NULL);
	ft_putstr("cpydone\n");
	displaytest(new);
	curr = clrmap(&curr);
	ft_putstr("clrdone\n");
	return (new);
}

t_map		**parseline(char *str, t_env *e)
{
	char 	**tab;
	int		col;
	t_map **ln;

	ft_putstr(str);
	ft_putstr("\n");
	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(ln = (t_map **)malloc(sizeof(t_map *) * (len_of_tab(tab) + 1))))
		return (NULL);
	col = 0;
	ft_putstr("koko\n");
	displaytest(e->map);
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
	displaytest(e->map);
	return (ln);
}

t_env		*initenv(int fd)
{
	char	*str;
	int		y;
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	//e->mlx = mlx_init();
	e->map = NULL;
	y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		printf("---------------------------------------------------------------\n");
		printf("---------------------------y = %d------------------------------\n", y);
		printf("---------------------------------------------------------------\n");
		ft_putstr("okok\n");
		e->map = newline(e->map);
		ft_putstr("coolcool\n");
		displaytest(e->map);
		e->map[y] = parseline(str, e);
		free(str);
		displaytest(e->map);
		ft_putstr("les bons gateaux\n");
		ft_putstr(e->map[y][0]->color);
		ft_putstr("\n");
		y++;
	}
	ft_putstr(e->map[--y][0]->color);
	ft_putstr("wtf\n");
	while (1)
	{

	}
	ft_putstr(e->map[0][0]->color);
	ft_putstr("wtf\n");
	return (e);
}
