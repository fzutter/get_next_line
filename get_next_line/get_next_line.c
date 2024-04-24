/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:37:54 by fzutter           #+#    #+#             */
/*   Updated: 2024/04/24 21:30:09 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*temp_line(int fd, char *backup, char *buf)
{
	ssize_t		read_line;
	char		*char_temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free (char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	ssize_t	count;
	char	*temp;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == 0 || line[1] == 0)
		return (NULL);
	temp = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*temp == 0)
	{
		free(temp);
		temp = NULL;
	}
	line[count + 1] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(backup);
		backup = NULL;
		buf = NULL;
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = temp_line(fd, backup, buf);
	free(buf);
	buf = NULL;
	if (line == NULL)
		return (NULL);
	backup = extract(line);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	return (0);
}
*/