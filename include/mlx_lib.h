/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_lib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 12:59:06 by evoronin      #+#    #+#                 */
/*   Updated: 2024/04/04 16:07:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LIB_H
# define MLX_LIB_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
#  define TEXWIDTH 512
#  define TEXHEIGHT 512
#  define MV_SP 1
#  define RT_SP 5
# endif

# include "../include/cub3D.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <string.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	o;
	int	c;
}	t_color;


typedef struct s_wall
{
	mlx_texture_t	*tex;
}	t_wall;


typedef struct s_rays
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				start;
	int				end;
	double			ray_dir_x;
	double			ray_dir_y;
	t_wall			walls[4];
}	t_rays;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	double		pos_x; //player position x
	double		pos_y; //player position y
	double		dir_x; //initial direction vector
	double		dir_y; //initial direction vector
	double		plane_x; //the 2d raycaster version of the camera plane
	double		plane_y; //the 2d raycaster version of the camera plane
	double		time; //time of current frame
	double		old_time; //time of previous frame
}	t_data;

//init_screen
int			init_screen(t_map *map);
void		init_loop(t_data *data);
void		draw_layout(t_data *data, t_map *map);
void		game_loop(t_data *data);
void		cast_ray(t_data *data, t_rays *ray);
void		cast_ray_next(t_rays *ray, t_data *data);
void		init_ray_struct(t_rays *ray, t_data *data);
void		dda(t_data *data, t_rays *ray);
void		calc_line(t_data *data, t_rays *ray, int x);
int32_t		ft_color_one(t_data *data, t_rays *ray);
uint32_t	ft_color_two(int *color);
void		paint_line(t_data *data, t_rays *ray, int x, int line_h);
void		find_delta(t_rays *ray);

//hooks
void		ft_hooks(mlx_key_data_t k, void *param);
//texture
uint32_t	find_pixel(t_rays *ray, uint32_t x, uint32_t y);
int			ft_pixel(int r, int g, int b);
void		fill_texture(t_data *data, t_rays *ray);



#endif
