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

int			l_line(t_map **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putstr("\n");
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
	{
		ft_strcpy(color, BASE_COLOR);
		return (color);
	}
	ft_strcpy(color, str);
	return (color);
}

int cpymap(t_map ****new, t_map ***curr, int len)
{
 	int i;
	int	j;

 	i = 0;
	ft_putnbr(len);
 	while (i < len)
 	{
		ft_putstr("cc\n");
		if (!((*new)[i] = (t_map **)malloc(sizeof(t_map *) * (l_line(curr[i]) + 1))))
			return (0);
		ft_putstr("cc2\n");
 		j = 0;
		while (curr[i][j])
		{
			if (!((*new)[i][j] = (t_map *)malloc(sizeof(t_map))))
				return (0);
			(*new)[i][j]->z = curr[i][j]->z;
			(*new)[i][j]->color = getcolor(curr[i][j]->color);
			j++;
		}
		ft_putstr("j = ");
		ft_putnbr(j);
		ft_putstr("\n");
		(*new)[i][j] = NULL;
		i++;
	}
	ft_putnbr(i);
	(*new)[i] = NULL;
	(*new)[i + 1] = NULL;
	return (1);
}

void *clrmap(t_map ****curr)
{
	int i;
	int j;

	displaytest(*curr);
	i = 0;
	if ((*curr)[8])
		ft_putstr("hmm\n");
	while ((*curr)[i])
	{
		ft_putnbr(i);
		ft_putstr("allo\n");
		j = 0;
		while ((*curr)[i][j])
		{
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putstr(" : ");
			ft_putnbr((*curr)[i][j]->z);
			ft_putstr("\n");
			//ft_memdel((void **)&(*curr)[i][j]->color);
			//ft_memdel((void **)&(*curr)[i][j]);
			j++;
		}
		ft_memdel((void **)&(*curr)[i]);
		ft_putstr("cc\n");
		i++;
	}
	free(*curr);
	return (NULL);
}
