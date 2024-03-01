/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsemap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:40:29 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/01 15:16:48 by yitoh         ########   odam.nl         */
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
