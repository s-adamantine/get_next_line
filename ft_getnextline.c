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
	char	*substring;

	substring = ft_strnew(BUFF_SIZE); //because the largest size that you can possibly get into is buff size anyway.
	//should I null terminate this? should I?
	*line = substring;
	while (*buf && *buf != '\n')
	{
		*substring++ = *buf++;
	}
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
			return (0);
		}
		else
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			return (0);
		}
	}
	buf = ft_memalloc(BUFF_SIZE + 1);
	while (read(fd, buf, BUFF_SIZE) > 0) //while you can read
	{
		printf("buf: %s\n", buf);
		if (ft_strchr(buf, '\n'))
		{
			grab_substring(line, buf);
			buf = recopy_buf(buf);
			return (0);
		}
	}
	return (-1);
}
