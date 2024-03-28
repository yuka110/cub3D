/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:18:41 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 12:12:01 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

uint32_t    find_pixel(t_data *data, uint32_t x, uint32_t y)
{
	mlx_texture_t   *t;
	t_color          col;

	printf("x %d\n", col.r);
	printf("y %d\n", col.r);
	if (data->map->map2d[x][y] == 5)
		t = mlx_load_png(data->map->n_tex);
	if (data->map->map2d[x][y] == 6)
		t = mlx_load_png(data->map->e_tex);
	if (data->map->map2d[x][y] == 7)
		t = mlx_load_png(data->map->s_tex);
	if (data->map->map2d[x][y] == 8)
		t = mlx_load_png(data->map->w_tex);
	col.r = t->pixels[(y * t->width + x) * t->bytes_per_pixel];
	col.g = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 1];
	col.b = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 2];
	col.c = ft_pixel(col.r, col.g, col.b);
	return(col.c);
}


// if (c == 'N')
// 		return (5);
// 	if (c == 'E')
// 		return (6);
// 	if (c == 'S')
// 		return (7);
// 	if (c == 'W')
// 		return (8);