/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:51:41 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/16 16:35:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Headers
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct	s_map
{
	int		n_fd;
	int		s_fd;
	int		w_fd;
	int		e_fd;
	char	**init_map;
	int		*floor;
	int		*ceiling;
}	t_map;


#endif