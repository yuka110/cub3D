/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:18:41 by evoronin      #+#    #+#                 */
/*   Updated: 2024/04/10 13:41:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	fill_texture(t_data *data, t_rays *ray)
{
	ray->walls[0].tex = mlx_load_png(data->map->e_tex);
	ray->walls[1].tex = mlx_load_png(data->map->w_tex);
	ray->walls[2].tex = mlx_load_png(data->map->s_tex);
	ray->walls[3].tex = mlx_load_png(data->map->n_tex);
	if (!ray->walls[0].tex || !ray->walls[1].tex || !ray->walls[2].tex
		|| !ray->walls[3].tex)
	{
		if (ray->walls[0].tex)
			mlx_delete_texture(ray->walls[0].tex);
		if (ray->walls[1].tex)
			mlx_delete_texture(ray->walls[1].tex);
		if (ray->walls[2].tex)
			mlx_delete_texture(ray->walls[2].tex);
		if (ray->walls[3].tex)
			mlx_delete_texture(ray->walls[3].tex);
		ft_error("failed to load texture", data->map);
	}
}

t_text	find_tex(t_rays *ray)
{
	t_text	t;

	if (ray->ray_dir_y >= 0 && ray->side == 1)
		t.t = ray->walls[2].tex;
	else if (ray->ray_dir_y <= 0 && ray->side == 1)
		t.t = ray->walls[3].tex;
	else if (ray->ray_dir_x >= 0 && ray->side == 0)
		t.t = ray->walls[1].tex;
	else
		t.t = ray->walls[0].tex;
	return (t);
}

uint32_t	find_pixel(mlx_texture_t *t, uint32_t x, uint32_t y)
{
	t_color			col;

	col.r = t->pixels[(y * t->width + x) * 4];
	col.g = t->pixels[(y * t->width + x) * 4 + 1];
	col.b = t->pixels[(y * t->width + x) * 4 + 2];
	col.c = ft_pixel(col.r, col.g, col.b);
	return (col.c);
}
