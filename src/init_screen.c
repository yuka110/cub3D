/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 11:41:46 by evoronin      #+#    #+#                 */
/*   Updated: 2024/04/09 12:07:52 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	game_loop(t_data *data)
{
	t_rays	ray;

	ray.hit = 0;
	ray.map_x = data->pos_x;
	ray.map_y = data->pos_y;
	cast_ray(data, &ray);
	mlx_delete_texture(ray.walls[0].tex);
	mlx_delete_texture(ray.walls[1].tex);
	mlx_delete_texture(ray.walls[2].tex);
	mlx_delete_texture(ray.walls[3].tex);
}

t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_error("data struct malloc failed", NULL);
	data->map = map;
	data->pos_x = map->px + 0.5;
	data->pos_y = map->py + 0.5;
	data->dir_x = 0;
	data->dir_y = 0;
	if (map->map2d[map->py][map->px] == 5)
		data->dir_y = 1;
	else if (map->map2d[map->py][map->px] == 6)
		data->dir_x = 1;
	else if (map->map2d[map->py][map->px] == 7)
		data->dir_y = 1;
	else if (map->map2d[map->py][map->px] == 8)
		data->dir_x = -1;
	data->plane_x = 0;
	data->plane_y = 0.66;
	return (data);
}

int	init_screen(t_map *map)
{
	t_data	*data;

	data = init_data(map);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!data->mlx)
	{
		free (data);
		ft_error("mlx init", map);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		free(data);
		mlx_terminate(data->mlx);
		ft_error("img init", map);
	}
	draw_layout(data, map);
	game_loop(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_key_hook(data->mlx, ft_hooks, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free (data);
	return (0);
}
