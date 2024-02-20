/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsemap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:40:29 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/20 19:15:42 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
			if (ft_strlen(tmp[i]) > map->width)
				map->width = ft_strlen(tmp[i]);
		}
		i++;
	}
	ft_printf("\nwidth is %d, depth is %d\n\n", map->width, map->depth);
}

char	**parse_map(char **tmp, t_map *map)
{
	int	i;
	int	k;
	int	row;

	i = 0;
	row = 0;
	width_depth(tmp, map, 0, 0);
	map->map2d = ft_calloc(map->depth + 1, sizeof (char *));
	if (!map->map2d)
		return (NULL);
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == '1')
		{
			map->map2d[row] = ft_calloc(map->width + 1, sizeof(char));
			if (!map->map2d[row])
				return (NULL);
			k = ft_strlcpy(map->map2d[row], tmp[i], map->width);
			// ft_printf("k is %d\n", k);
			if (k < map->width && ft_strchr("\n\0", map->map2d[row][k]))
				map->map2d[row] = ft_memset(map->map2d[row] + k - 1, ' ', map->width - k);
			// ft_printf("map->map2d[%d]: %s\n", row, map->map2d[row]);
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

	color = ft_calloc(4, sizeof(int));
	ft_printf("yayyyy\n");
	if (!color)
		return (NULL);
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == id && ft_strchr(" \t", tmp[i][k + 1]))
			break ;
		i++;
	}
	ft_printf("yayyyy\n");

	if (!tmp[i])
		return (NULL);
	ft_printf("tmp[%d] + %d + 2 = %s\n", i, k, tmp[i] + k + 2);
	arr = ft_split(tmp[i] + k + 2, ',');
	if (!arr)
		return (NULL);
	k = 0;
	while (arr[k])
	{
		color[k] = ft_atoi(arr[k]);
		k++;
	}
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
	// map->map2d = parse_map(tmp, map);
	// if (!map->map2d)
	// {
	// 	ft_freearrs(tmp);
	// 	ft_error("map->2d malloc failed", map);
	// }
	// ft_printarr(map->map2d);
	// map->ceiling = parse_color(tmp, 'C', 0, 0);
	// map->floor = parse_color(tmp, 'F', 0, 0);
	// if (!map->ceiling || !map->floor)
	// {
	// 	ft_freearrs(tmp);
	// 	ft_error("malloc failed", map);
	// }

	//should we keep opening the fds?
	return (map);
}
