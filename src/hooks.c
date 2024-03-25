/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:55:30 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/25 14:54:42 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

//prob need to add sin cos + if condition should be revised
// void	move_updown(mlx_key_data_t k, t_data *data, int **map)
// {
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && k.action == MLX_PRESS)
// 	{
// 		if (!(map[(int)(data->pos_y + (data->dir_y * MV_SP))][(int)data->pos_x]))
// 			data->pos_y += data->dir_y * MV_SP;
// 		if (!(map[(int)data->pos_y][(int)(data->pos_x + (data->dir_x * MV_SP))]))
// 			data->pos_x += data->dir_x * MV_SP;
// 		draw_layout(data, data->map);
// 		game_loop(data);
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_S) && k.action == MLX_PRESS)
// 	{

// 		if (!(map[(int)(data->pos_y - (data->dir_y * MV_SP))][(int)data->pos_x]))
// 			data->pos_y -= data->dir_y * MV_SP;
// 		if (!(map[(int)data->pos_y][(int)(data->pos_x - (data->dir_x * MV_SP))]))
// 			data->pos_x -= data->dir_x * MV_SP;
// 		draw_layout(data, data->map);
// 		game_loop(data);
// 	}
// }

// void	move_side(mlx_key_data_t k, t_data *data, int **map)
// {
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && k.action == MLX_PRESS)
// 	{
// 		if ((data->pos_x + (data->dir_y * MV_SP)) >= 0
// 			&& (data->pos_x + (data->dir_y * MV_SP)) < data->map->width
// 			&& !(map[(int)data->pos_y][(int)(data->pos_x + (data->dir_y * MV_SP))]))
// 			data->pos_x += data->dir_y * MV_SP;
// 		if (data->pos_y + (data->dir_x * MV_SP) >= 0
// 			&& data->pos_y + (data->dir_x * MV_SP) < data->map->depth
// 			&&!(map[(int)(data->pos_y + (data->dir_x * MV_SP))][(int)data->pos_x]))
// 			data->pos_y += data->dir_x * MV_SP;
// 		draw_layout(data, data->map);
// 		game_loop(data);
// 	}
// 	else if (mlx_is_key_down(data->mlx, MLX_KEY_D) && k.action == MLX_PRESS)
// 	{
// 		if (!(map[(int)data->pos_y][(int)(data->pos_x - (data->dir_y * MV_SP))]))
// 			data->pos_x -= data->dir_y * MV_SP;
// 		if (!(map[(int)(data->pos_y - (data->dir_x * MV_SP))][(int)data->pos_x]))
// 			data->pos_y -= data->dir_x * MV_SP;
// 		draw_layout(data, data->map);
// 		game_loop(data);
// 	}
// }

void	rotate_view(t_data *data, int right)
{
	int	rotspeed;

	rotspeed = 5;
	if (!right)
		rotspeed = -5;
	data->dir_y += rotspeed * (M_PI / 180);
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && k.action == MLX_REPEAT)
		rotate_view(data, true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && k.action == MLX_REPEAT)
		rotate_view(data, false);
	// move_updown(k, data, data->map->map2d);
	// move_side(k, data, data->map->map2d);

}
