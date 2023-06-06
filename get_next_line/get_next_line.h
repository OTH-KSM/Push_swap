/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:02:26 by okassimi          #+#    #+#             */
/*   Updated: 2023/05/06 17:58:06 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_pouss
{
	char		*temp;
	char		*buffer;
	char		*line;
	int			rdd;
	int			jeton;
	int			j;
	int			check;
}t_pos;

char	*get_next_line(int fd);
char	*ft_strdup_o(const char *s1);
char	*ft_strjoin_o(char *s1, char *s2);
size_t	ft_strlen_o(const char *str);
char	*ft_strchr_o(char *s, int c);
char	*ft_substr_o(char *s, unsigned int start, size_t len);

#endif