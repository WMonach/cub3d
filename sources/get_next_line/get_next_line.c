/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:53:36 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/11/29 13:11:52 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*buffer_separator(char *buffer, char *line)
{
	if (!check_newline(buffer))
	{
		ft_newline_separator(buffer);
		line = ft_strjoin_gnl(line, buffer);
		if (line && line[0] == '\0')
		{
			free(line);
			line = NULL;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			index;

	index = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = buffer_separator(buffer, line);
	while (index > 0 && (check_newline(buffer)))
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index <= 0)
			return (line);
		buffer[index] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
