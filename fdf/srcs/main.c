/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:00:22 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/23 19:39:16 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_env	*e;
	int		fd;

	if (ac != 2)
		exit (err_found("usage : fdf input_map"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit (err_found("open failed"));
	if (!(e = initenv(fd)))
		exit (err_found("a problem occured during the parsing."));
	return (1);
}
