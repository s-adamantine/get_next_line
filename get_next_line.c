/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:54:09 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/10 19:54:17 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void   		expand_line(char **line)
{
	char	*expanded;

	expanded = ft_strnew(ft_strlen(*line) + BUFF_SIZE); //strnew vs memalloc hmm one possible extra byte
	ft_strcpy(expanded, *line);
	*line = expanded;
}

/*
** grabs characters from the buffer to line (until a \n) and clears off grabbed characters from buffer.
*/
char	*transfer(char **line, char *buf)
{
	int		i;
	char	*substring;
	char	*new_buf;

	i = 0;
	substring = ft_strnew(BUFF_SIZE);
	new_buf = ft_strnew(BUFF_SIZE);
	while (*buf && *buf != '\n')
	{
		substring[i++] = *buf++;
	}
	ft_strcat(*line, substring);
	if (ft_strchr(buf, '\n'))
		ft_strcpy(new_buf, ft_strchr(buf, '\n') + 1);
	else
		ft_bzero(new_buf, BUFF_SIZE);
	return (new_buf);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;

	*line = ft_memalloc(BUFF_SIZE);
	if (fd < 0)
		return (-1);
	if (buf)
	{
		buf = transfer(line, buf);
		if (!*buf)
			expand_line(line);
		else
			return (1);
	}
	buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		buf = transfer(line, buf);
		if (!*buf)
			expand_line(line);
		else
			return (1);
	}
	if (**line)
		return (1);
	return (0);
}
