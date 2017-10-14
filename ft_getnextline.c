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

	expanded = (char *)malloc(sizeof(char) * (ft_strlen(line) + BUFF_SIZE + 1));
	ft_strcpy(expanded, line);
	// // printf("%s\n", expanded);
	// free(line);
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
			if (ft_strlen(*line) == 0) 				//the beginning of *line
			{
				ft_strlcat(*line, buf, BUFF_SIZE);
			}
			else
			{
				line2 = (char *)malloc(sizeof(char) * ft_strlen(*line));
				ft_strcpy(line2, *line);
				free(*line);
				*line = (char *)malloc(sizeof(char) * (ft_strlen(line2) + BUFF_SIZE + 1));
				ft_strcpy(*line, line2);
				ft_strncat(*line, buf, BUFF_SIZE);
				printf("sizeof *line: %lu\n", sizeof(*line));
				printf("line is: %s\n", *line);
			}
		}
		else if (len < BUFF_SIZE - 1)
		{
			// *line = expand_line(*line); // commented out bc haven't tested but may be useful
			printf("line right before: %s\n", *line);
			ft_strncat(*line, buf, len);
			printf("line right after: %s\n", *line);
			return (0);
		}
	}
	close(fd);
	return (0);
}
