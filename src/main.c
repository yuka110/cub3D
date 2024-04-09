/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:59:52 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/09 17:55:29 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/mlx_lib.h"

int	main(int ac, char **av)
{
	t_map	*map;
	char	**tmp;

	if (ac != 2)
		ft_error("number of argument is not good", NULL);
	tmp = ft_parsecub(av[1]);
	if (ft_checkmap(tmp, 0, 0, 0))
	{
		ft_freearrs(tmp);
		ft_error("map is invalid", NULL);
	}
	map = ft_initmap(tmp);
	ft_freearrs(tmp);
	init_screen(map);
}
