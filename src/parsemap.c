/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsemap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:40:29 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/29 17:24:16 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	width_depth(char **tmp, t_map *map, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == '1')
		{
			map->depth++;
			if (ft_strlen(tmp[i]) - 1 > map->width)
				map->width = ft_strlen(tmp[i]) - 1;
		}
		i++;
	}
//	ft_printf("\n-----------------\nwidth is %d, depth is %d\n-----------------\n", map->width, map->depth);
}

int	*strcpy_atoi(int *dst, char *src, int width)
{
	int	i;

	i = 0;
	if (src && dst)
	{
		while (src[i] && src[i] != '\n')
		{
			if (src[i] != '1' && src[i] != '0')
				dst[i] = -1;
			else
				dst[i]= src[i] - 48;
			++i;
		}
		while (i < width)
		{
			dst[i] = -1;
			i++;
		}
	}
	return (dst);
}

int	**parse_map(char **tmp, t_map *map)
{
	int	i;
	int	k;
	int	row;

	i = 0;
	row = 0;
	width_depth(tmp, map, 0, 0);
	map->map2d = ft_calloc(map->depth + 1, sizeof (int *));
	if (!map->map2d)
		return (NULL);
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == '1')
		{
			map->map2d[row] = ft_calloc(map->width + 1, sizeof(int));
			if (!map->map2d[row])
				return (NULL);
			map->map2d[row] = strcpy_atoi(map->map2d[row], tmp[i], map->width);
			row++;
		}
		i++;
	}
	return (map->map2d);
}

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
