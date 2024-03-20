/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 17:55:30 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/20 18:35:28 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

// void	ft_rotate(void *data)
// {
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_W))
// 		((t_data*)data)->dir_x -= 3 * (M_PI / 180);
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_A))
// 		((t_data*)data)->dir_x += 3 * (M_PI / 180);
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_S))
// 		((t_data*)data)->dir_y -= 3 * (M_PI / 180);
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_D))
// 		((t_data*)data)->dir_y += 3 * (M_PI / 180);
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_RIGHT))
// 		((t_data*)data)->zaxis -= 3 * (M_PI / 180);
// 	if (mlx_is_key_down(((t_data*)data)->win, MLX_KEY_LEFT))
// 		((t_data*)data)->zaxis += 3 * (M_PI / 180);
// 	draw_layout(data, data->map);
	
// 	return ;
// }


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
	{
		data->dir_y += 3 * (M_PI / 180);
		draw_layout(data, data->map);
		game_loop(data);

	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && k.action == MLX_REPEAT)
	{
		data->dir_y -= 3 * (M_PI / 180);
		draw_layout(data, data->map);
		game_loop(data);
	}
}
