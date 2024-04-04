/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:55:30 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/04 16:21:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

//prob need to add sin cos + if condition should be revised
void	move_updown(mlx_key_data_t k, t_data *data, int **map)
{
	double	mv_x;
	double	mv_y;

	mv_x = 0;
	mv_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && k.action == MLX_PRESS)
	{
		mv_x = -cos(data->dir_y) * MV_SP;
		mv_y = -sin(data->dir_y) * MV_SP;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S) && k.action == MLX_PRESS)
	{
		mv_x = cos(data->dir_y) * MV_SP;
		mv_y = sin(data->dir_y) * MV_SP;
	}
	if ((mv_x || mv_y) && (map[(int)(data->pos_y + mv_y)][(int)data->pos_x] != 1)
		&& (map[(int)data->pos_y][(int)(data->pos_x + mv_x)] != 1))
	{
		printf("change up down\n");
		data->pos_x += mv_x;
		data->pos_y += mv_y;
		draw_layout(data, data->map);
		game_loop(data);
	}
}

void	move_side(mlx_key_data_t k, t_data *data, int **map)
{
	double	mv_x;
	double	mv_y;

	mv_x = 0;
	mv_y = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && k.action == MLX_PRESS)
	{
		mv_x = sin(data->dir_y) * MV_SP;
		mv_y = -cos(data->dir_y) * MV_SP;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D) && k.action == MLX_PRESS)
	{
		mv_x = -sin(data->dir_y) * MV_SP;
		mv_y = cos(data->dir_y) * MV_SP;
	}
	if ((mv_x || mv_y) && (map[(int)(data->pos_y + mv_y)][(int)data->pos_x] != 1)
		&& (map[(int)data->pos_y][(int)(data->pos_x + mv_x)] != 1))
	{
		printf("change side\n");
		data->pos_x += mv_x;
		data->pos_y += mv_y;
		draw_layout(data, data->map);
		game_loop(data);
	}
}

void	rotate_view(t_data *data, int right)
{
	double	angle;

	angle = 0;
	if (right)
		angle -= RT_SP * (M_PI / 180);
	else
		angle += RT_SP * (M_PI / 180);
	data->dir_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	data->dir_y = data->dir_x * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) - data->plane_y * sin(angle);
	data->plane_y = data->plane_x * sin(angle) + data->plane_y * cos(angle);
	// printf("angle %f, dirX %f, diry %f, planex %f, planey %f\n", angle, data->dir_x, data->dir_y, data->plane_x, data->plane_y);
	draw_layout(data, data->map);
	game_loop(data);
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && k.action == MLX_PRESS)
		rotate_view(data, true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && k.action == MLX_PRESS)
		rotate_view(data, false);
	move_updown(k, data, data->map->map2d);
	move_side(k, data, data->map->map2d);
}
