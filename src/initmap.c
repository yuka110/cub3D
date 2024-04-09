/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 15:14:45 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/09 12:15:35 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	find_colorid(char **tmp, char id, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] == id)
			break ;
		i++;
	}
	return (i);
}

int	*parse_color(char **tmp, char id, int i, int k)
{
	int		*color;
	char	**arr;

	i = find_colorid(tmp, id, i, k);
	if (!tmp[i])
		return (NULL);
	arr = ft_split(tmp[i] + k + 1, ',');
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

char	*dup_texture(char *tmp, int k)
{
	char	*file;

	file = ft_strdup(tmp + k);
	if (!file)
		return (NULL);
	k = ft_strlen(file) - 1;
	while (k >= 0 && ft_strchr(" \t\n", file[k]))
	{
		file[k] = '\0';
		k--;
	}
	return (file);
}

void	parse_texture(char **tmp, t_map **map, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (!ft_strncmp(tmp[i] + k, "NO", 2))
			(*map)->n_tex = dup_texture(tmp[i], k + 3);
		else if (!ft_strncmp(tmp[i] + k, "SO", 2))
			(*map)->s_tex = dup_texture(tmp[i], k + 3);
		else if (!ft_strncmp(tmp[i] + k, "WE", 2))
			(*map)->w_tex = dup_texture(tmp[i], k + 3);
		else if (!ft_strncmp(tmp[i] + k, "EA", 2))
			(*map)->e_tex = dup_texture(tmp[i], k + 3);
		i++;
	}
	if (!(*map)->n_tex || !(*map)->s_tex || !(*map)->e_tex || !(*map)->w_tex)
	{
		ft_freearrs(tmp);
		ft_error("texture malloc failed", *map);
	}
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
	map->map2d = parse_map(tmp, map, 0, 0);
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
		ft_error("color malloc failed", map);
	}
	parse_texture(tmp, &map, 0, 0);
	return (map);
}
