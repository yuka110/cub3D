/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 14:20:04 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/07 12:57:51 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_lib.h"

static int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_color(t_data *data, t_rays *ray)
{
	t_color	col;

	if (data->map->map2d[ray->map_y][ray->map_x] == '1')
		col.c = ft_pixel(0, 0, 0, 255);
	else
		col.c = ft_pixel(255, 255, 255, 255);
	return (col.c);
}
