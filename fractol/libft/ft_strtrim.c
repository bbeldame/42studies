/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:11:45 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/13 21:28:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *str)
{
	int i;
	int start;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	i--;
	if (i == -1 && str[0] != ' ' && str[0] != '\n' && str[0] != '\t')
		i = 0;
	if (str[i + 1] == '\0')
		i = 0;
	start = i;
	while (str[i])
		i++;
	if (str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t')
		i--;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && i != 0)
		i--;
	return (i - start);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (count((char *)s) + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	str = ft_strncpy(str, s + i, count((char *)s));
	str[count((char *)s)] = '\0';
	return (str);
}
