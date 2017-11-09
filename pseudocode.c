
// char	*expand_line(char *line)
// {
// 	char	*expanded;
//
// 	expanded = ft_memalloc(ft_strlen(line) + BUFF_SIZE);
// 	ft_strcpy(expanded, line);
// 	free(line);
// 	return (expanded);
// }

void	recopy_buf(buf)
{

}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;

	*line = ft_memalloc(BUFF_SIZE); //result line
	//grabbing everything from buf if it already exists/if there's anything in buf.
	if (buf)
	{
		if (!ft_strchr(buf, '\n')) //if you can't find \n you'll end up returning null
			ft_strcpy(*line, buf); //so copy everything from that \n to the line
		else
			ft_strcpy(*line, ft_strchr(buf, '\n') - 1); //copy to line up until the new line.
		// now this is where you copy everything from buf that isn't input in line yet back to buf. (basically get rid of the beginning bits)
		recopy_buf(buf);
	}
	buf = ft_memalloc(BUFF_SIZE); //create buf if you haven't yet
	while (read(fd, buf, BUFF_SIZE) > 0) //while you can read
	{
		// so if line already exists, you want to ft_strcat it, but if it doesn't already exist, you'd want to do a simple ft_strcpy
		// unless ft_strcat cats even though you start from 0. actually it probably does?

		// if there isn't a new line:
		if (!ft_strchr(buf, '\n'))
		// copy everything into line, and repeat the reading process.
		// you can overwrite whatever is in buf with what's being read, so no need to worry about clearing.
		{
			ft_strcat(*line, buf);
			expand_line_and_read_again(lol);
		}
		else
			ft_strcat(*line, ft_strchr(buf, '\n')); //the code is probably wrong, but basically return line from buf to '\n', and then null terminate it.
			//!!!!!!!!!!!!need to figure out how to eliminate what's currently in the buffer from the beginning to the \n.
			recopy_buf(buf);
			return (0); //i think this is the return value for true for gnl
	}
	return (-1);
}
