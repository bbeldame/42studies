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

// changement de cette fonction plus tard
char		*getcolor(char *str)
{
	char *color;

	if (!(color = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	if (!str)
		return (BASE_COLOR);
	return (color);
}

int			len_of_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_pt		*parseline(char *str)
{
	char 	**tab;
	int		col;
	t_pt *ln;

	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(ln = (t_pt *)malloc(sizeof(t_pt) * (len_of_tab(tab)))))
		return (NULL);
	col = 0;
	while (col < len_of_tab(tab))
	{
		ln[col].z = ft_atoi(ft_strsplit(tab[col], ',')[0]);
		ln[col].color = getcolor(ft_strsplit(tab[col], ',')[1]);
		col++;
	}
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
	y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		e->map[y] = parseline(str);
		y++;
	}
	e->map[y] = NULL;
	return (e);
}
