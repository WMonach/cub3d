/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:54:14 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/11/29 13:11:19 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strnlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strnlen(s2) + 1));
	if (tab)
	{
		while (s1 && s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j] && (s2[j] != '\n'))
			tab[i++] = s2[j++];
		if (s2[j] == '\n')
			tab[i] = '\n';
		if (s2[j] == '\n')
			i++;
		tab[i] = '\0';
	}
	free(s1);
	return (tab);
}

void	ft_newline_separator(char	*s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s && (s[i] == '\n'))
		i++;
	while (j < BUFFER_SIZE - i)
	{
		s[j] = s[i + j];
		j++;
	}
	s[j] = '\0';
}
