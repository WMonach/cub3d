/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:35:57 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 18:39:53 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_ra_end_of_loop(float ra)
{
	ra += DR / (1919 / 60);
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	return (ra);
}

float	set_ra_before_loop(float ra, float pa)
{
	ra = pa - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	return (ra);
}