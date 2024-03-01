/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_lib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 12:59:06 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/01 16:39:35 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LIB_H
# define MLX_LIB_H

# include "../include/cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
}	t_data;

//init_screen
int		init_screen(t_map *map);
void	init_loop(t_data *data);
void	ft_hooks(mlx_key_data_t k, void *param);
void	cast_ray(t_data *data);
void	cast_ray_next(t_data *data);

#endif
