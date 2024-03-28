/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:46:58 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/28 12:10:07 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	paint_line(t_data *data, t_rays *ray, int x)
{
	int			y;
	int			y_max;
	uint32_t	t_x;
	uint32_t	t_y;
	uint32_t	col;
	double		wall;

	y = ray->start;
	y_max = ray->end;
	wall = data->pos_x + ray->side_dist_x;
	t_x = wall * 64;
	while (y < y_max)
	{
		t_y = (int)((y - HEIGHT/  2 + ray->side_dist_y / 2 ) * ray->step_y) & (64 - 1);
		col = find_pixel(data, t_x, t_y);
		mlx_put_pixel(data->img, x, y, col);
		y++;
	}
}

void	draw_layout(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->img, x, y, ft_color_two(map->ceiling));
			else
				mlx_put_pixel(data->img, x, y, ft_color_two(map->floor));
			x++;
		}
		y++;
	}
}
