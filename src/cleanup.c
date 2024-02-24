/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 17:25:02 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/24 17:11:09 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_freeintarrs(int **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	ft_freearrs(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	ft_error(char *msg, t_map *map)
{
	if (map)
	{
		if (map->map2d)
			ft_freeintarrs(map->map2d);
		if (map->floor)
			free(map->floor);
		if (map->ceiling)
			free(map->ceiling);
		free(map);
	}
	ft_printf("Error: %s\n", msg);
	exit(1);
}

void	ft_cleanup(t_map *map)
{
	ft_freeintarrs(map->map2d);
	free(map->ceiling);
	free(map->floor);

	free(map);
	exit(0);
}
