/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_lib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 12:59:06 by evoronin      #+#    #+#                 */
/*   Updated: 2024/03/09 12:05:23 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LIB_H
# define MLX_LIB_H

# include "../include/cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	o;
	int	c;
}	t_color;

typedef struct s_rays
{
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}	t_rays;

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
void	cast_ray_next(t_rays *ray, t_data *data, double ray_dir_x,
			double ray_dir_y);
void	init_ray_struct(t_rays *ray, t_data *data, double ray_dir_x,
			double ray_dir_y);
void	dda(t_data *data, t_rays *ray);
void	calc_line(t_data *data, t_rays *ray);
int32_t	ft_color(t_data *data, t_rays *ray);


int		test_screen(t_map *map);

#endif
