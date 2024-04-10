/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:55:30 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/10 15:03:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	move_updown(t_data *data, int **map)
{
	double	mv_x;
	double	mv_y;

	mv_x = 0;
	mv_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		mv_x = (data->dir_x) * MV_SP;
		mv_y = (data->dir_y) * MV_SP;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		mv_x = -(data->dir_x) * MV_SP;
		mv_y = -(data->dir_y) * MV_SP;
	}
	if ((mv_x || mv_y)
		&& (map[(int)(data->pos_y + mv_y)][(int)data->pos_x] != 1)
		&& (map[(int)data->pos_y][(int)(data->pos_x + mv_x)] != 1))
	{
		data->pos_x += mv_x;
		data->pos_y += mv_y;
		draw_layout(data, data->map);
		game_loop(data);
	}
}

void	move_side(t_data *data, int **map)
{
	double	mv_x;
	double	mv_y;

	mv_x = 0;
	mv_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		mv_x = -data->plane_x * MV_SP;
		mv_y = -data->plane_y * MV_SP;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		mv_x = data->plane_x * MV_SP;
		mv_y = data->plane_y * MV_SP;
	}
	if ((mv_x || mv_y)
		&& (map[(int)(data->pos_y + mv_y)][(int)data->pos_x] != 1)
		&& (map[(int)data->pos_y][(int)(data->pos_x + mv_x)] != 1))
	{
		data->pos_x += mv_x;
		data->pos_y += mv_y;
		draw_layout(data, data->map);
		game_loop(data);
	}
}

void	rotate_view(t_data *data, int right)
{
	double	angle;
	double	cp_dirx;
	double	cp_planex;

	angle = 0;
	if (right)
		angle += RT_SP * (M_PI / 180);
	else
		angle -= RT_SP * (M_PI / 180);
	cp_dirx = data->dir_x;
	cp_planex = data->plane_x;
	data->dir_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	data->dir_y = cp_dirx * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) - data->plane_y * sin(angle);
	data->plane_y = cp_planex * sin(angle) + data->plane_y * cos(angle);
	draw_layout(data, data->map);
	game_loop(data);
}

void	ft_hooks(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(data->mlx, data->img);
		mlx_close_window(data->mlx);
		free(data);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_view(data, true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_view(data, false);
	move_updown(data, data->map->map2d);
	move_side(data, data->map->map2d);
}
