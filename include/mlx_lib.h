/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_lib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 12:59:06 by evoronin      #+#    #+#                 */
/*   Updated: 2024/02/29 17:24:16 by elenavoroni   ########   odam.nl         */
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
	int32_t		width;
	int32_t		height;
	int32_t		y;
	int32_t		x;
}	t_data;

//init_screen
int		init_screen(t_map *map);


#endif
