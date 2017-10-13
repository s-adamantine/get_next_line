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

char	**check_contents(char *line)
{
	char	**lines;

	lines = ft_strsplit(line, '\n');
	return (lines);
}

int		get_line_length(char *line)
{
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
	{
		len++;
	}
	return (len);
}

int		get_next_line(const int fd, char **line)
{
	int			len;
	static char	*buf;
	static char	*saved;


	// *line = ft_memalloc(BUFF_SIZE); //result line
	buf = ft_memalloc(BUFF_SIZE); //what you read into
	// *line = ft_memalloc(BUFF_SIZE); //result line
	saved = ft_memalloc(BUFF_SIZE);
	*line = ft_memalloc(BUFF_SIZE); //result line

	while(read(fd, buf, BUFF_SIZE) > 0)
	{
		len = get_line_length(buf);
		if (len == BUFF_SIZE)
		{
			ft_strcat(*line, buf);
		}
		else if (len < BUFF_SIZE)
		{
			ft_strncat(*line, buf, len);
			return (0);
		}
	}
	close(fd);
	return (0);
}
