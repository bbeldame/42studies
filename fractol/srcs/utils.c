/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:20:46 by bbeldame          #+#    #+#             */
/*   Updated: 2017/03/22 20:31:04 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

DL			ft_map(DL x, DL size, DL min, DL max)
{
	return ((x / size) * (max - min) + min);
}
