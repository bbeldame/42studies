/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

void	free_splited_str(char **str)
{
	int i;
	ft_putstr("blbl\n");
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	ft_putstr("blblalafin\n");
}
