/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsemap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:40:29 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/19 18:06:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


// char	**parse_map(char **tmp)
// {

// }

int	*parse_color(char **tmp, char id, int i, int k)
{
	int		*color;
	char	**arr;

	color = ft_calloc(4, sizeof(int));
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
		ft_printf("Error: malloc failed\n");
		ft_freearrs(tmp);
		exit (1);
	}
	// map->map2d = parse_map(tmp);
	// map->ceiling = parse_color(tmp, 'C', 0, 0);
	// map->floor = parse_color(tmp, 'F', 0, 0);
	//should we keep opening the fds?
	return (map);
}
