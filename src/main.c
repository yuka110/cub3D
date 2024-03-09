/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:59:52 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/09 12:50:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		ft_error("number of argument is not good", NULL);
	map = ft_init(av[1]);
	ft_printf("parsing is done:)\n");
	if(init_screen(map) != 0)
		ft_error("MLX error", NULL);
	// if(test_screen(map) != 0)
	// 	ft_error("MLX error", NULL);
	ft_cleanup(map);
}
