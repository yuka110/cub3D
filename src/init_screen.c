/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 11:41:46 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/20 14:36:38 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	paint_line(t_data *data, t_rays *ray, int start, int end, int x)
{
	int	y;
	int	y_max;

	y = start;
	y_max = end;
	while (y < y_max)
	{
		printf("HERE\n");
		mlx_put_pixel(data->img, x, y, ft_color_one(data, ray));
		y++;
	}
}

void	calc_line(t_data *data, t_rays *ray, int x)
{
	int	line_h;
	int	start;
	int	end;

	line_h = (int)(HEIGHT / ray->perp_wall_dist);
	// printf("ray->perp_wall_dist: %f\n", ray->perp_wall_dist);
	start = -line_h / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_h / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	paint_line(data, ray, start, end, x);
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
		if (ray->map_x >= data->map->width || ray->map_y >= data->map->depth)
		{
			ray->hit = 1;
			return ;
		}
		if (data->map->map2d[(int)ray->map_x][(int)ray->map_y] > 0)
			ray->hit = 1;
	}
}

void	init_ray_struct(t_rays *ray, t_data *data)
{
	ray->hit = 0;
	ray->map_x = data->pos_x;
	ray->map_y = data->pos_y;
}

void	cast_ray_next(t_rays *ray, t_data *data, double ray_dir_x,
			double ray_dir_y)
{
	if (ray_dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray_dir_y);
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
	printf("dist_x %f\n", ray->delta_dist_x);
	printf("delta x %f\n", ray->side_dist_x);
	printf("dist y %f\n", ray->delta_dist_y);
	printf("delta y%f\n", ray->side_dist_y);
	dda(data, ray);
}

void	cast_ray(t_data *data, t_rays *ray)
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
		cast_ray_next(ray, data, ray_dir_x, ray_dir_y);
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		else
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		calc_line(data, ray, x);
		x++;
	}
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
}

void	draw_layout(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->img, x, y, ft_color_two(map->ceiling));
			else
				mlx_put_pixel(data->img, x, y, ft_color_two(map->floor));
			x++;
		}
		y++;
	}
}

void	game_loop(t_data *data)
{
	t_rays	*ray;

	ray = NULL;
	ray = ft_calloc(1, sizeof(t_rays));
	if (!ray)
	{
		free(data);
		mlx_terminate(data->mlx);
		ft_error("ray init", data->map);
	}
	init_ray_struct(ray, data);
	cast_ray(data, ray);
	free(ray);
}

int	init_screen(t_map *map)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_error("data struct malloc failed", NULL);
	data->map = map;
	data->pos_x = map->px;
	data->pos_y = map->py;
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
