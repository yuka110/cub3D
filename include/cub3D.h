/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:51:41 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/27 13:57:05 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 700
# define HEIGHT 700

// Headers
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../Libft/libft.h"

typedef struct s_map
{
	int		n_fd;
	int		s_fd;
	int		w_fd;
	int		e_fd;
	int		**map2d;
	int		*floor;
	int		*ceiling;
	int		depth;
	int		width;
}	t_map;



//init
t_map	*ft_init(char *cubfile);
void	ft_printarr(char **tmp);

//checkmap
int		ft_checkmap(char **tmp, int i, int k);

//parsemap
t_map	*ft_initmap(char **tmp);

//cleanup
void	ft_freearrs(char **s);
void	ft_freeintarrs(int **s);
void	ft_error(char *msg, t_map *map);
void	ft_cleanup(t_map *map);

//testprint
void	ft_printarr(char **tmp);
void	ft_printintarrs(int **tmp, int width);
void	ft_printmap(t_map *map);

#endif