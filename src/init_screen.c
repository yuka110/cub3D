/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 11:41:46 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/01 16:41:16 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	cast_ray_next(t_data *data)
{
	int mapX = int(posX);
	int mapY = int(posY);
	  //length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;
	   //length of ray from one x or y-side to next x or y-side
	double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
	double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
	double perpWallDist;
	  //what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
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
	cast_ray_next(data);
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

	data->map = map;
	data->pos_x = map->px;
	data->pos_y = map->py;
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	init_loop(map);
	mlx_terminate(data->mlx);
	// ft_free();
	return (0);
}
