/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:01 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:41 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines(t_data *data, int fd, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (1);
		}
		data->nb_of_lines++;
		free(line);
	}
}

int	check_file(char *file, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		count_lines(data, fd, line);
		fd = open(file, O_RDONLY);
		if (check_file_loop(data, line, fd, i) == 1)
			return (1);
		close(fd);
		return (0);
	}
	return (1);
}

int	check_extension(char *str, char *extension)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != extension[i])
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	check_file_format(char *file, t_data *data)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (file[i] == '.' && file[i + 1] != '\0')
		i++;
	else
		return (1);
	if (check_extension(&file[i], "cub") == 1)
		return (1);
	data->check = 1;
	return (0);
}
