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

int			len_of_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			len_of_line(t_map **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// changement de cette fonction plus tard
char		*getcolor(char *str)
{
	char	*color;
	int	len;

	len = (!str) ? ft_strlen(BASE_COLOR) : ft_strlen(str);
	if (!(color = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!str)
		return (BASE_COLOR);
	return (color);
}

t_map		***cpymap(t_map ***new, t_map ***curr, int len)
{
 	int i;
	int	j;

 	i = 0;
	ft_putnbr(len);
 	while (i < len)
 	{
		ft_putstr("cc\n");
		if (!(new[i] = (t_map **)malloc(sizeof(t_map *) * len_of_line(curr[i]))))
			return (NULL);
		ft_putstr("cc2\n");
 		j = 0;
		while (curr[i][j])
		{
			if (!(new[i][j] = (t_map *)malloc(sizeof(t_map))))
				return (NULL);
			new[i][j]->z = curr[i][j]->z;
			new[i][j]->color = getcolor(curr[i][j]->color);
			ft_putstr(new[i][j]->color);
			j++;
		}
		new[i][j] = NULL;
		i++;
	}
	new[i] = NULL;
	return (new);
}

void *clrmap(t_map ****curr)
{
	int i;
	int j;

	i = 0;
	while (*curr[i])
	{
		ft_putstr("allo\n");
		j = 0;
		while (*curr[i][j])
		{
			ft_putstr("blabla\n");
			free(*curr[i][j]->color);
			ft_putstr("reblabla\n");
			free(*curr[i][j]);
			ft_putstr("rereblabla\n");
			j++;
		}
		ft_putstr("cc\n");
		i++;
	}
	return (NULL);
}
