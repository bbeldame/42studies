/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/30 19:56:57 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			err_found(char *str)
{
	ft_putendl_fd(str, 2);
	return (3);
}

void		free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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
			ft_putnbr(map->coor[i][j++]);
			ft_putstr(", ");
		}
		i++;
		ft_putstr("\n");
	}
	ft_putstr("-------------------------FIN-------------------------------\n");
}
