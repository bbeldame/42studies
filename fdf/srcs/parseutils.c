/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:51:39 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			err_found(char *str) {
	ft_putendl_fd(str, 2);
	return (3);
}

int			len_of_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			l_line(t_map **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/* changement de cette fonction plus tard */
char		*getcolor(char *str)
{
	char	*color;
	int		len;

	len = (!str) ? ft_strlen(BASE_COLOR) : ft_strlen(str);
	if (!(color = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!str)
	{
		ft_strcpy(color, BASE_COLOR);
		return (color);
	}
	ft_strcpy(color, str);
	return (color);
}

int			cpymap(t_map ****new, t_map ***curr, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		if (!((*new)[i] =
			(t_map **)malloc(sizeof(t_map) * (l_line(curr[i]) + 1))))
			return (0);
		j = 0;
		while (curr[i][j])
		{
			if (!((*new)[i][j] = (t_map *)malloc(sizeof(t_map))))
				return (0);
			(*new)[i][j]->z = curr[i][j]->z;
			(*new)[i][j]->color = getcolor(curr[i][j]->color);
			j++;
		}
		(*new)[i][j] = NULL;
		i++;
	}
	(*new)[i] = NULL;
	(*new)[i + 1] = NULL;
	return (1);
}

void		*clrmap(t_map ****curr)
{
	int		i;
	int		j;

	i = 0;
	while ((*curr)[i])
	{
		j = 0;
		while ((*curr)[i][j])
		{
			ft_memdel((void **)&(*curr)[i][j]->color);
			ft_memdel((void **)&(*curr)[i][j]);
			j++;
		}
		ft_memdel((void **)&(*curr)[i]);
		i++;
	}
	ft_memdel((void **)&(*curr));
	return (NULL);
}
