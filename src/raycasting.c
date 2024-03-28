/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:44:54 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 13:08:14 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	calc_line(t_data *data, t_rays *ray, int x)
{
	int	line_h;

	line_h = (int)(HEIGHT / ray->perp_wall_dist);
	ray->start = -line_h / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = line_h / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	paint_line(data, ray, x, line_h);
}

void	dda(t_data *data, t_rays *ray)
{
	ray->hit = 0;
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
		if (data->map->map2d[ray->map_y][ray->map_x] > 0)
			ray->hit = 1;
	}
}

void	find_delta(t_rays *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = abs(1 / ray->ray_dir_y);
}

void	cast_ray_next(t_rays *ray, t_data *data)
{
	find_delta(ray);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
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

void	cast_ray(t_data *data, t_rays *ray)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < WIDTH)
	{
		ray->map_x = data->pos_x;
		ray->map_y = data->pos_y;
		camera_x = 2 * x / ((double)WIDTH) - 1;
		ray->ray_dir_x = data->dir_x + data->plane_x * camera_x;
		ray->ray_dir_y = data->dir_y + data->plane_y * camera_x;
		cast_ray_next(ray, data);
		if (ray->side == 0)
		{
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		}
		else
		{
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		}
		calc_line(data, ray, x);
		x++;
	}
}
