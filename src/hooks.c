/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:55:30 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/21 10:54:06 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

// void	move_player(mlx_key_data_t k, keys_t key, t_data *data)
// {
// 	if (mlx_is_key_down(data->mlx, key) && k.action == MLX_REPEAT)
// 		data->pos_y 
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && k.action == MLX_REPEAT)
// 		data->dir_
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_S) && k.action == MLX_REPEAT)
// 		data->dir_y -= 3 * (M_PI / 180);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_D) && k.action == MLX_REPEAT)
// 	{
// 		data->dir_y -= 3 * (M_PI / 180);
// 		draw_layout(data, data->map);
// 		game_loop(data);
// 	}
// }

void	rotate_view(t_data *data, int right)
{
	int	rotspeed;

	rotspeed = 3;
	if (!right)
		rotspeed = -3;
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
}
