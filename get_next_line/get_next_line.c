/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:37:54 by fzutter           #+#    #+#             */
/*   Updated: 2024/04/09 15:23:29 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	
	read(fd, buf, 4)




}

char    *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	left_c;

    if (fd == -1)
		return(NULL);
	left_c = malloc(BUFFER_SIZE + 1);
	if (left_c == 0)
		return (NULL);
    *_fill_line_buffer(fd, left_c, *buffer);
}
int main()
{
    int fd;
    fd = open("text.txt", O_RDONLY);
}