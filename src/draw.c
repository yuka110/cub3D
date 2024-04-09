/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:46:58 by evoronin      #+#    #+#                 */
/*   Updated: 2024/04/09 16:48:26 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	paint_line(t_data *data, t_rays *ray, int x, int line_h)
{
	t_text			t;

	t = find_tex(ray);
	if (ray->side == 0)
		t.wall_x = data->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		t.wall_x = data->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	t.wall_x -= floor(t.wall_x);
	t.t_x = (int)(t.wall_x * (double)t.t->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		t.t_x = t.t->width - t.t_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		t.t_x = t.t->width - t.t_x - 1;
	t.step = 1.0 * t.t->height / line_h;
	t.tex_pos = (ray->start - ((double)HEIGHT / 2) + ((double)line_h / 2))
		* t.step;
	while (ray->start < ray->end)
	{
		t.t_y = (int)t.tex_pos;
		t.tex_pos += t.step;
		mlx_put_pixel(data->img, x, ray->start,
			find_pixel(t.t, t.t_x, t.t_y));
		ray->start++;
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
