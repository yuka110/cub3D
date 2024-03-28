/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:18:41 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 13:46:19 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

uint32_t	find_pixel(t_data *data, t_rays *ray, uint32_t x, uint32_t y)
{
	mlx_texture_t	*t;
	t_color			col;

	(void)data;
	if (ray->ray_dir_y >= 0 && ray->side == 1)
		t = mlx_load_png(data->map->e_tex);
	else if (ray->ray_dir_y <= 0 && ray->side == 1)
		t = mlx_load_png(data->map->w_tex);
	else if (ray->ray_dir_x >= 0 && ray->side == 0)
		t = mlx_load_png(data->map->s_tex);
	else
		t = mlx_load_png(data->map->n_tex);
	puts(mlx_strerror(mlx_errno));
	col.r = t->pixels[(y * t->width + x) * t->bytes_per_pixel];
	col.g = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 1];
	col.b = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 2];
	col.c = ft_pixel(col.r, col.g, col.b);
	return (col.c);
}


// if (c == 'N')
// 		return (5);
// 	if (c == 'E')
// 		return (6);
// 	if (c == 'S')
// 		return (7);
// 	if (c == 'W')
// 		return (8);