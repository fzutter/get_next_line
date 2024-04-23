/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:37:54 by fzutter           #+#    #+#             */
/*   Updated: 2024/04/23 16:29:29 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*temp_line(int fd, char *buf, char *backup)
{
	ssize_t		read_line;
	char		*char_temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
//		printf("Read line : %d\n", read_line);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
//		printf("Buf1 : %s\n", buf);
		buf[read_line] = '\0';
//		printf("Buf2 : %s\n", buf);
		if (backup == NULL)
			backup = ft_strdup("");
		char_temp = backup;
//		printf("Backup1 : %s\n", backup);
		backup = ft_strjoin(char_temp, buf);
		free (char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
//	printf("Backup2 : %s\n", backup);
	return (backup);
}

static char	*extract(char *line)
{
	ssize_t	count;
	char	*temp;

	count = 0;
//	printf("Line : %s\n", line);
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
//	printf("Temp : %s\n", temp);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = temp_line(fd, buf, backup);
//	printf("Buf : %s\n", buf);
//	printf("Line : %s\n", line);
	free(buf);
	buf = NULL;
	if (line == NULL)
		return (NULL);
	backup = extract(line);
//	printf("Line : %s\n", line);
//	printf("Backup : %s\n", backup);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("../workspace/text.txt", O_RDONLY);
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