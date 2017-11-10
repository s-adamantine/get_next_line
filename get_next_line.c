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

	expanded = ft_memalloc(ft_strlen(*line) + BUFF_SIZE); //is it a good idea to do buff size or buff size + 1
	ft_strcpy(expanded, *line);
	*line = expanded;
}

static char	*recopy_buf(char *buf)
{
	char	*new_buf;

	new_buf = ft_memalloc(BUFF_SIZE);
	if (ft_strchr(buf, '\n'))
		ft_strcpy(new_buf, ft_strchr(buf, '\n') + 1); //copy to the temp everything from buf after the first \n. FUCKING UP HERE
	else
		new_buf = NULL;
	return (new_buf);
}

/*
** copy from the beginning to a '\n'
*/
void	grab_substring(char **line, char *buf)
{
	int		i;
	char	*substring;

	i = 0;
	substring = ft_strnew(BUFF_SIZE);
	while (*buf && *buf != '\n')
	{
		substring[i++] = *buf++;
	}
	ft_strcat(*line, substring);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;

	*line = ft_memalloc(BUFF_SIZE);
	if (buf)
	{
		if (ft_strchr(buf, '\n'))
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			return (1);
		}
		else
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			expand_line(line);
		}
	}
	buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0) //while you can read
	{
		if (ft_strchr(buf, '\n'))
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			return (1);
		}
		else
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			expand_line(line);
		}
		free(buf);
		buf = ft_memalloc(BUFF_SIZE + 1);
	}
	return (-1);
}
