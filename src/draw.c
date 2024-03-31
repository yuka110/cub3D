/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:46:58 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/31 17:36:40 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	paint_line(t_data *data, t_rays *ray, int x, int line_h)
{
	int			y;
	int			y_max;
	uint32_t	t_x;
	uint32_t	t_y;
	uint32_t	col;
	double		wall_x;
	double		step;
	double		tex_pos;

	y = ray->start;
	y_max = ray->end;
	if (ray->side == 0)
		wall_x = data->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	step = 1 * (float)TEXHEIGHT / (float)line_h;
	// printf ("step:%f = 512/%d     ", step, line_h);
	tex_pos = (y - (HEIGHT / 2) + (line_h / 2)) * step;
	t_x = (int)(wall_x * (double)TEXWIDTH);
	// printf (" text_pos %f = %d - 350 + (%d/2) * %f\n", tex_pos, y, line_h, step);
	// t_y is actually not moving -> either step is wrong or text_pos original value is too off
	while (y < y_max)
	{
		t_y = (int)tex_pos & (TEXHEIGHT - 1);
		tex_pos += step;
		col = find_pixel(ray, t_x, t_y);
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
