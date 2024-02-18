/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 16:59:52 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/18 17:11:22 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		ft_error("number of argument is not good");
	map = ft_init(av[1]);
	ft_freemap(map);
}