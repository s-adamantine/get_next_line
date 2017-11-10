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
	char	*old_line;
	char	*expanded;

	old_line = *line;
	expanded = ft_strnew(ft_strlen(*line) + BUFF_SIZE); //strnew vs memalloc hmm one possible extra byte
	ft_strcpy(expanded, *line);
	free(old_line);
	*line = expanded;
}

/*
** grabs characters from the buffer to line (until a \n) and clears off grabbed characters from buffer.
*/
char	*transfer(char **line, char *buf)
{
	int		i;
	int		j;
	char	*grab;

	i = 0;
	j = 0;
	grab = ft_strnew(BUFF_SIZE);
	while (buf[i] && buf[i] != '\n')
	{
		grab[i] = buf[i];
		i++;
	}
	ft_strcat(*line, grab);
	if (ft_strchr(buf, '\n'))
	{
		i++;
		while (buf[i])
			buf[j++] = buf[i++];
		buf[j] = '\0';
	}
	else
		ft_bzero(buf, BUFF_SIZE);
	free(grab);
	return (buf);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_memalloc(BUFF_SIZE);
	if (buf)
	{
		buf = transfer(line, buf);
		if (!*buf)
			expand_line(line);
		else
			return (1);
	}
	else
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
