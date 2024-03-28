/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:18:41 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 16:39:55 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	fill_texture(t_data *data, t_rays *ray)
{
	ray->walls[0].tex = mlx_load_png(data->map->e_tex);
	printf("e: %s\n", data->map->e_tex);
	ray->walls[1].tex = mlx_load_png(data->map->w_tex);
	ray->walls[2].tex = mlx_load_png(data->map->s_tex);
	ray->walls[3].tex = mlx_load_png(data->map->n_tex);
	if (!ray->walls[0].tex || !ray->walls[1].tex || !ray->walls[2].tex
		|| !ray->walls[3].tex)
		ft_error("failed to open png", data->map);
}

uint32_t	find_pixel(t_rays *ray, uint32_t x, uint32_t y)
{
	mlx_texture_t	*t;
	t_color			col;

	if (ray->ray_dir_y >= 0 && ray->side == 1)
		t = ray->walls[0].tex;
	else if (ray->ray_dir_y <= 0 && ray->side == 1)
	{
		t = ray->walls[1].tex;
		printf("HERE\n");
	}
	else if (ray->ray_dir_x >= 0 && ray->side == 0)
		t = ray->walls[3].tex;
	else
		t = ray->walls[4].tex;
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