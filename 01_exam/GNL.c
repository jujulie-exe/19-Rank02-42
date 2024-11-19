
char	*ft_strdup(char *s)
{
	char *dup;
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while(s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(fd)
{
	static char 	buffer[BUFFER_SIZE];
	static int	bytes_read;
	static int	buffer_index;
	int		i;
	char		line[70000];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read <= 0)
				break;
		}
		if (line [i] == '\n')
			break;
		line[i] = buffer[buffer_idex];
		buffer++;
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return(ft_strdup(line));
}
