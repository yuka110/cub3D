/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 10:46:58 by evoronin      #+#    #+#                 */
/*   Updated: 2024/04/09 12:06:47 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

void	paint_line(t_data *data, t_rays *ray, int x, int line_h)
{
	int			t_x;
	int			t_y;
	double		wall_x;
	double		step;
	double		tex_pos;

	if (ray->side == 0)
		wall_x = data->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	t_x = (int)(wall_x * (double)TEXWIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		t_x = TEXWIDTH - t_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		t_x = TEXWIDTH - t_x - 1;
	step = 1.0 * TEXHEIGHT / line_h;
	tex_pos = (ray->start - (HEIGHT / 2) + (line_h / 2)) * step;
	while (ray->start < ray->end)
	{
		t_y = (int)tex_pos & (TEXHEIGHT - 1);
		tex_pos += step;
		mlx_put_pixel(data->img, x, ray->start, find_pixel(ray, t_x, t_y));
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
// test drawing texture to image
// void	draw_layout(t_data *data, t_map *map)
// {
// 	int	x;
// 	int	y;
// 	mlx_texture_t	*t;
// 	t_color			col;

// 	(void) map;
// 	t = mlx_load_png(data->map->e_tex);
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			col.r = t->pixels[(y * WIDTH + x) * t->bytes_per_pixel];
// 			// y * 512
// 			col.g = t->pixels[(y * WIDTH + x) * t->bytes_per_pixel + 1];
// 			col.b = t->pixels[(y * WIDTH + x) * t->bytes_per_pixel + 2];
// 			col.c = ft_pixel(col.r, col.g, col.b);
// 			mlx_put_pixel(data->img, x, y, col.c);
// 			x++;
// 		}
// 		y++;
// 	}
// }
