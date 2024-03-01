/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:54:49 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/01 15:16:50 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	*parse_color(char **tmp, char id, int i, int k)
{
	int		*color;
	char	**arr;

	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == id && ft_strchr(" \t", tmp[i][k + 1]))
			break ;
		i++;
	}
	if (!tmp[i])
		return (NULL);
	arr = ft_split(tmp[i] + k + 2, ',');
	if (!arr)
		return (NULL);
	color = ft_calloc(4, sizeof(int));
	if (!color)
		return (NULL);
	k = 0;
	while (k < 3)
	{
		color[k] = ft_atoi(arr[k]);
		k++;
	}
	ft_freearrs(arr);
	return (color);
}

t_map	*ft_initmap(char **tmp)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_freearrs(tmp);
		ft_error("map struct malloc failed", NULL);
	}
	map->map2d = parse_map(tmp, map);
	if (!map->map2d)
	{
		ft_freearrs(tmp);
		ft_error("map->2d malloc failed", map);
	}
	map->ceiling = parse_color(tmp, 'C', 0, 0);
	map->floor = parse_color(tmp, 'F', 0, 0);
	if (!map->ceiling || !map->floor)
	{
		ft_freearrs(tmp);
		ft_error("malloc failed", map);
	}
	// check the textures maybe under checkmap?
	return (map);
}

t_map	*ft_init(char *cubfile)
{
	t_map	*map;
	char	**tmp;

	tmp = ft_parsecub(cubfile);
	if (ft_checkmap(tmp, 0, 0))
	{
		ft_freearrs(tmp);
		ft_error("map is invalid", NULL);
	}
	map = ft_initmap(tmp);
	ft_printmap(map);
	ft_freearrs(tmp);
	return (map);
}
