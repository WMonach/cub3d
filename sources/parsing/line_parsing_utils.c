/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:31:45 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 13:15:11 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file_opening(char *file, int size)
{
	int		i;
	int		fd;
	int		length;
	char	*str;

	i = 0;
	length = 0;
	i += size;
	while (file[i] == 9 || file[i] == 32)
		i++;
	while (file[length + i] != '\n')
		length++;
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (1);
	ft_strlcpy(str, &file[i], length);
	fd = open(str, O_RDONLY);
	free(str);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_path_to_texture(t_data *data, int i, int size)
{
	int		j;
	char	*str;

	j = 0;
	str = &data->line_tmp[i];
	j += size;
	while (str[j] == 9 || str[j] == 32)
		j++;
	while (str[j] && str[j] != '.')
		j++;
	if (str[j] == '.' && str[j + 1] != '\0')
		j++;
	if (check_extension(&str[j], "xpm") == 1)
	{
		printf("Error : wrong texture file format : need .xpm\n");
		return (1);
	}
	if (check_file_opening(str, size) == 1)
	{
		printf("Error : can't open file\n");
		return (1);
	}
	return (0);
}

int	last_line(char *line, int i)
{
	if (line[i - 1] != '\n')
		return (i + 1);
	else
		return (i);
}

int	check_if_line_is_map(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (data->texture.check_all_id == 1)
	{
		while (line[i] == 9 || line[i] == 32)
			i++;
		if (line && line[i] == '1')
			return (0);
	}
	return (1);
}

int	check_chars(char *line, char *chars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		j = 0;
		while (chars[j])
		{
			if (line[i] == chars[j])
				count++;
			j++;
		}
		i++;
	}
	i = last_line(line, i);
	if (count != (i - 1))
	{
		printf("Error : the map contains a forbidden char\n");
		return (1);
	}
	return (0);
}
