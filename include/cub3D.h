/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:51:41 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/29 18:22:11 by yitoh         ########   odam.nl         */
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
	size_t		n_fd;
	size_t		s_fd;
	size_t		w_fd;
	size_t		e_fd;
	int			**map2d;
	int			*floor;
	int			*ceiling;
	size_t		depth;
	size_t		width;
	int			px; //player's position
	int			py;
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
