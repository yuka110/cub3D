/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 14:20:04 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 11:38:45 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_lib.h"

int	ft_pixel(int r, int g, int b)
{
	return ((uint32_t)(r << 24) | (uint32_t)(g << 16)
			| (uint32_t)(b << 8) | 255);
}

int32_t	ft_color_one(t_data *data, t_rays *ray)
{
	uint32_t	col;

	(void)ray;
	(void)data;
	// if (data->map->map2d[ray->map_y][ray->map_x] == '1')
	// 	col.c = ft_pixel(0, 0, 0);
	// else
	col = ft_pixel(255, 255, 255);
	return (col);
}

uint32_t	ft_color_two(int *color)
{
	uint32_t	col;

	col = ft_pixel(color[0], color[1], color[2]);
	return (col);
}
