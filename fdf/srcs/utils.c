/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/02/01 20:08:53 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		err_found(char *str)
{
	ft_putendl_fd(str, 2);
	exit(3);
}

void		free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}

void		*semalloc(size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		err_found("malloc failed");
	return (new);
}

int			len_of_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		displaytest(t_map *map)
{
	int		i;
	int		j;

	ft_putstr("------------------------DEBUT-----------------------------\n");
	i = 0;
	while (i < map->m_ln)
	{
		j = 0;
		while (j < map->m_col)
		{
			ft_putnbr(map->coor[i][j++].z);
			ft_putstr(", ");
		}
		i++;
		ft_putstr("\n");
	}
	ft_putstr("-------------------------FIN-------------------------------\n");
}
