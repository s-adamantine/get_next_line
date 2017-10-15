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

/*
	Current task: figuring out how to expand the line properly w/ malloc
	Next: grab whatever is inside the buffer.
*/

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

char	*expand_line(char *line)
{
	char	*expanded;

	expanded = ft_memalloc(ft_strlen(line) + BUFF_SIZE);
	ft_strcpy(expanded, line);
	free(line);
	return (expanded);
}

int		get_next_line(const int fd, char **line)
{
	int			len;
	char		*line2;
	static char	*buf;

	*line = ft_memalloc(BUFF_SIZE); //result line
	buf = ft_memalloc(BUFF_SIZE); //what you read into
	while(read(fd, buf, (BUFF_SIZE - 1)) > 0)
	{
		len = get_line_length(buf);
		if (len == BUFF_SIZE - 1)
		{
			if (ft_strlen(*line) == 0) 	//the beginning of *line
			{
				ft_strcat(*line, buf);
			}
			else
			{
				*line = expand_line(*line);
				ft_strcat(*line, buf);
			}
		}
		else if (len < BUFF_SIZE - 1)
		{
			*line = expand_line(*line); //why does this function work even w/o this line
			ft_strncat(*line, buf, len);
			return (0);
		}
	}
	return (-1);
}
