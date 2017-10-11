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

int	get_line_length(char *line)
{
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
	{
		len++;
	}
	return (len);
}

int	get_next_line(const int fd, char **line)
{
	int		len;
	char	*buf;

	buf = ft_memalloc(BUFF_SIZE); //what you read into
	*line = ft_memalloc(BUFF_SIZE); //result line
	read(fd, buf, BUFF_SIZE);
	len = get_line_length(buf);
	if (len == BUFF_SIZE)
	{
		ft_strcat(*line, buf);
		//repeat again
	}
	else if (len < BUFF_SIZE)
	{
		ft_strncat(*line, buf, len);
		return (0);
	}
	printf("%d", len);
	printf("%s\n", buf);
	close(fd);
	return (0);
}
