/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_lib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 12:59:06 by evoronin      #+#    #+#                 */
/*   Updated: 2024/02/27 13:45:14 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LIB_H
# define MLX_LIB_H

#include "cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t		width;
	int32_t		height;
	int32_t		y;
	int32_t		x;
}	t_data;

//init_screen
int		init_screen(t_map *map);


#endif