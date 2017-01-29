/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:08:31 by bbeldame          #+#    #+#             */
/*   Updated: 2017/01/18 21:23:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

# define BUFF_SIZE	4200
# define NBMAXFD	9000

typedef struct		s_cont
{
	int				fd;
	char			*ctt;
}					t_cont;

int					get_next_line(const int fd, char **line);

#endif
