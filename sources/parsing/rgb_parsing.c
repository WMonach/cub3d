/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:02:21 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/11/29 15:56:54 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_range_rgb_value(t_data *data)
{
	int	tmp;

	tmp = ft_atoi(data->rgb_value);
	if (tmp > 255 || tmp < 0)
	{
		printf("Error : RGB value not in correct range : [0 ; 255]\n");
		free(data->rgb_value);
		return (1);
	}
	return (0);
}

int	check_rgb_value(t_data *data, char *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[size] && str[size] != ',')
		size++;
	data->length += size + 1;
	data->rgb_value = malloc(sizeof(char) * (size + 1));
	if (!data->rgb_value)
		return (1);
	while (str[i] && str[i] != ',')
	{
		data->rgb_value[i] = str[i];
		i++;
	}
	data->rgb_value[i] = '\0';
	if (check_range_rgb_value(data) == 1)
		return (1);
	free(data->rgb_value);
	return (0);
}

int	check_last_value_and_commas(int k, int commas)
{
	if (k == 0)
		return (1);
	if (k > 3)
	{
		printf("Error : RGB value must be inferior to 255\n");
		return (1);
	}
	if (commas != 2)
	{
		printf("Error : wrong RGB value : need 3 numbers from 0 to 255\n");
		return (1);
	}
	return (0);
}

int	checking_loop_for_rgb(t_data *data, char *str, int j, int k)
{
	while (str[j] && str[j] != '\n')
	{
		if (ft_isdigit(str[j]) == 0)
		{
			if (str[j] == ',')
			{
				data->check_comma++;
				if (k > 3)
				{
					printf("Error : RGB value must be inferior to 255\n");
					return (0);
				}
				else
					k = -1;
			}
			else
			{
				printf("Error : RGB value needs to be a number\n");
				return (0);
			}
		}
		k++;
		j++;
	}
	return (k);
}

int	check_rgb(t_data *data, int i)
{
	int		j;
	int		k;
	int		tmp;
	char	*str;

	j = 0;
	k = 0;
	data->check_comma = 0;
	str = &data->line_tmp[i];
	j++;
	while (str[j] == 9 || str[j] == 32)
		j++;
	tmp = j;
	k = checking_loop_for_rgb(data, str, j, k);
	if (check_last_value_and_commas(k, data->check_comma) == 1)
		return (1);
	j = 0;
	while (j < 3)
	{
		if (check_rgb_value(data, &str[tmp + data->length]) == 1)
			return (1);
		j++;
	}
	return (0);
}
