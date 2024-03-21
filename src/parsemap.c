/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsemap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:40:29 by yitoh         #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2024/03/21 10:57:08 by evoronin      ########   odam.nl         */
=======
/*   Updated: 2024/03/21 11:01:48 by yitoh         ########   odam.nl         */
>>>>>>> 5d1d824 (norm a bit)
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
			if ((int)ft_strlen(tmp[i]) - 1 > map->width)
				map->width = ft_strlen(tmp[i]) - 1;
		}
		i++;
	}
}

int	assign_posvalue(char c, t_map *map, int i, int row)
{
	map->px = i;
	map->py = row;
	if (c == 'N')
		return (5);
	if (c == 'E')
		return (6);
	if (c == 'S')
		return (7);
	if (c == 'W')
		return (8);
	return (-1);
}

int	*strcpy_atoi(int *dst, char *src, t_map *map, int row)
{
	int	i;

	i = 0;
	if (src && dst)
	{
		while (src[i] && src[i] != '\n')
		{
			if (ft_strchr("NSEW", src[i]))
				dst[i] = assign_posvalue(src[i], map, i, row);
			else if (src[i] != '1' && src[i] != '0')
				dst[i] = -1;
			else
				dst[i] = src[i] - 48;
			++i;
		}
		while (i < (int)map->width)
		{
			dst[i] = -1;
			i++;
		}
	}
	return (dst);
}

int	**parse_map(char **tmp, t_map *map, int row, int i)
{
	int	k;

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
			map->map2d[row] = strcpy_atoi(map->map2d[row], tmp[i], map, row);
			row++;
		}
		i++;
	}
	return (map->map2d);
}
