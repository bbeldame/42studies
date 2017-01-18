/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:45:29 by bbeldame          #+#    #+#             */
/*   Updated: 2016/11/13 21:26:19 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*clear(char **str)
{
	int j;

	j = 0;
	while (str[j])
		free(str[j++]);
	free(str[j]);
	free(str);
	return (NULL);
}

static int		lenpls(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1))))
		return (NULL);
	while (j < countwords(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[j] = (char *)malloc(sizeof(char) * (lenpls(s + i, c) + 1))))
			return (clear(str));
		str[j] = ft_strncpy(str[j], s + i, lenpls(s + i, c));
		str[j][lenpls(s + i, c)] = '\0';
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	str[j] = NULL;
	return (str);
}
