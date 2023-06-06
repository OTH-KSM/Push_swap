/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:56:54 by okassimi          #+#    #+#             */
/*   Updated: 2023/05/06 18:01:40 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_o(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;
	char	*p;

	lens1 = ft_strlen_o(s1);
	lens2 = ft_strlen_o(s2);
	i = 0;
	p = malloc((lens1 + lens2) * (sizeof(char) + 1));
	if (!p)
		return (0);
	j = 0;
	if (i < (lens1 + lens2))
	{
		while (i < lens1)
			p[i++] = s1[j++];
		j = 0;
		while (i < (lens1 + lens2))
			p[i++] = s2[j++];
	}
	p[i] = '\0';
	free (s1);
	return (p);
}

char	*ft_strchr_o(char *s, int c)
{
	char	*str;
	int		i;
	char	ca;
	int		lend;

	str = (char *)s;
	i = 0;
	ca = (char)c;
	lend = ft_strlen_o(s);
	if (!s)
		return (0);
	while (i <= lend)
	{
		if (str[i] == ca)
			return (s + i + 1);
		i++;
	}
	return (0);
}

char	*ft_substr_o(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen_o(s) || s[i] == '\0')
		return (ft_strdup_o(""));
	if (len > ft_strlen_o(s))
		len = ft_strlen_o(s) - start;
	s = s + start;
	p = malloc(len * sizeof(char) + 1);
	if (!p)
		return (0);
	while (s[i] && i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup_o(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = ft_strlen_o(s1);
	j = 0;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = 0;
	return (p);
}

size_t	ft_strlen_o(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
