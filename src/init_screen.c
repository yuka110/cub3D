/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 11:41:46 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/01 17:47:44 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	dda(t_data *data, t_rays *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map->map2d[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

void	init_ray_struct(t_rays *ray, t_data *data, double ray_dir_x,
			double ray_dir_y)
{
	ray->hit = 0;
	ray->map_x = data->pos_x;
	ray->map_y = data->pos_y;
	if (ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray_dir_y);
}

void	cast_ray_next(t_data *data, double ray_dir_x, double ray_dir_y)
{
	t_rays	*ray;

	ray = NULL;
	init_ray_struct(ray, data, ray_dir_x, ray_dir_x);
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->pos_x) * ray->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->pos_y) * ray->delta_dist_y;
	}
	dda(data, ray);
}

void	cast_ray(t_data *data)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = (2 * x) / ((double)WIDTH - 1);
		ray_dir_x = data->dir_x + data->plane_x * camera_x;
		ray_dir_y = data->dir_y + data->plane_y * camera_x;
		x++;
	}
	cast_ray_next(data, ray_dir_x, ray_dir_y);
}

void	ft_hooks(mlx_key_data_t k, void *param)
{
	t_data	*data;

	data = param;
	k.key = MLX_KEY_ESCAPE;
	if (mlx_is_key_down(data->mlx, k.key))
	{
		mlx_close_window(data->mlx);
		free(data);
		exit(EXIT_SUCCESS);
	}
	cast_ray(data);
}

void	init_loop(t_data *data)
{
	while (1)
	{
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		mlx_key_hook(data->mlx, ft_hooks, data);
		mlx_loop(data->mlx);
	}
}

int	init_screen(t_map *map)
{
	t_data	*data;

	data = NULL;
	data->map = map;
	data->pos_x = map->px;
	data->pos_y = map->py;
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	init_loop(data);
	mlx_terminate(data->mlx);
	// ft_free();
	return (0);
}
