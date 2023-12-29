/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:36:12 by oel-moue          #+#    #+#             */
/*   Updated: 2023/12/28 03:36:20 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if (s[i] == (char)c)
		return (s + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
