/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:38:54 by ocojeda-          #+#    #+#             */
/*   Updated: 2016/11/24 17:45:10 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	rm_spaces(char *s)
{
	size_t	i;
	size_t	spaces;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	spaces = i;
	if (s[i])
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			spaces++;
		}
	}
	return (len - spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	trim_len;

	if (s)
	{
		i = 0;
		j = 0;
		trim_len = rm_spaces((char *)s);
		str = (char *)malloc(sizeof(*str) * (trim_len + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (j < trim_len)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (char *)NULL;
}
