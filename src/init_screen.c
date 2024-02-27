/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/27 11:41:46 by evoronin      #+#    #+#                 */
/*   Updated: 2024/02/27 13:57:21 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx_lib.h"

// int	init_loop()
// {
// 	while ()
// }

int	init_screen(t_map *map)
{
	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	screen(WIDTH, HEIGHT, 0, "Raycaster");
	init_loop();
}