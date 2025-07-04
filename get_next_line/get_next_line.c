/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:03:29 by okassimi          #+#    #+#             */
/*   Updated: 2023/06/02 17:00:39 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	*ft_bzero_o(void *str, int n)
{
	char	*pt;
	int		i;

	pt = (char *)str;
	i = 0;
	while (i < n)
	{
		pt[i] = 0;
		i++;
	}
	return (0);
}

static	int	isthere_anl(char **temp, char **buffer, char *sta, int *j)
{	
	*buffer = ft_strdup_o("");
	*temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp || !buffer)
		return (-2);
	if (sta == NULL)
		return (0);
	if (sta[*j] == '\n')
		return (*j -1);
	while (sta[*j])
	{
		if (sta[*j] == '\n')
			return (*j);
		(*j)++;
	}
	return (0);
}

static	char	*ft_free(char **s1, char **s2, char **s3, int k)
{
	if (k == 0)
	{
		free(*s3);
		*s3 = NULL;
		return (*s3);
	}
	else if (k == 1)
	{
		free(*s1);
		free(*s2);
		return (NULL);
	}
	else
	{
		free(*s1);
		free(*s2);
		if (*s3[0] == '\0')
			*s3 = NULL;
		return (*s3);
	}
}

static	int	ft_checknl(char **buffer, char *tmp, int *jeton, int rdd)
{
	int	j;

	j = 0;
	if (rdd == 0)
		*jeton = 1;
	else
	{	
		if (*buffer[j] == '\n')
		{
			*jeton = 1;
			j = j - 1;
		}
		while (tmp[j])
		{
			if (tmp[j] == '\n')
			{	
				*jeton = 1;
				break ;
			}
			j++;
		}
		*buffer = ft_strjoin_o(*buffer, tmp);
		ft_bzero_o(tmp, BUFFER_SIZE);
	}
	return (j);
}

char	*get_next_line(int fd)
{
	static char		*sta;
	t_pos			pos;

	if (ft_bzero_o(&pos, sizeof(pos)) || fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	pos.check = isthere_anl(&pos.temp, &pos.buffer, sta, &pos.j);
	if (pos.check != 0)
		pos.jeton = 1;
	if (pos.check == -2)
		return (0);
	pos.buffer = ft_strjoin_o(pos.buffer, sta);
	ft_bzero_o(pos.temp, BUFFER_SIZE + 1);
	if (sta)
		sta = ft_free(&pos.temp, &pos.buffer, &sta, 0);
	while (pos.jeton == 0)
	{
		pos.rdd = read(fd, pos.temp, BUFFER_SIZE);
		if ((pos.rdd == 0 && pos.buffer[0] == '\0') || pos.rdd == -1)
			return (ft_free(&pos.temp, &pos.buffer, &sta, 1));
		pos.j += ft_checknl(&pos.buffer, pos.temp, &pos.jeton, pos.rdd);
	}
	pos.line = ft_substr_o(pos.buffer, 0, pos.j + 1);
	sta = ft_strchr_o(pos.buffer, '\n');
	sta = ft_substr_o(pos.buffer, pos.j + 1, ft_strlen_o(sta));
	return (ft_free(&pos.temp, &pos.buffer, &pos.line, 2));
}
