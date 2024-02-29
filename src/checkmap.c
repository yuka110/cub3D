/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkmap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 17:43:06 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/29 17:24:16 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_texture(char *png, int k)
{
	int	fd;

	while (ft_strchr(" \t", png[k]))
		k++;
	fd = open(png + k, O_RDONLY);
	if (fd < 0)
		return (1);
	close (fd);
	return (0);
}

int	check_color(char *color, int k)
{
	char	**arr;
	int		code;

	if (!ft_strchr(" \t", color[k]))
		return (1);
	while (ft_strchr(" \t", color[k]))
		k++;
	arr = ft_split(color, ',');
	if (!arr)
		return (1);
	k = 0;
	while (arr[k])
	{
		code = ft_atoi(arr[k]);
		if (code < 0 || code > 255)
		{
			ft_freearrs(arr);
			return (1);
		}
		k++;
	}
	ft_freearrs(arr);
	return (0);
}

int	check_nbr(char **tmp, int i, int k)
{
	if (tmp[i][k] != '1')
		return (ft_printf("first:%s\n", tmp[i] + k), 1);
	while (tmp[i][k])
	{
		if ((!tmp[i - 1] || ft_strchr(" \0", tmp[i - 1][k]))
			&& !ft_strchr("1 \t\n\0", tmp[i][k]))
			return (ft_printf("up\n"), 1);
		if ((!tmp[i + 1] || ft_strchr(" \0", tmp[i + 1][k]))
			&& !ft_strchr("1 \t\n\0", tmp[i][k]))
			return (ft_printf("down\n"), 1);
		if ((ft_strchr(" \t\n\0", tmp[i][k + 1]))
			&& !ft_strchr("1 \n\0", tmp[i][k]))
			return (ft_printf("right\n"), 1);
		if (!ft_strchr("01NSWE \t\n\0", tmp[i][k]))
			return (ft_printf("other\n"), 1);
		k++;
	}
	return (0);
}

//still need to check if there is duplicate
int	ft_checkmap(char **tmp, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (!ft_strncmp(tmp[i] + k, "NO", 2)
			|| !ft_strncmp(tmp[i] + k, "SO", 2)
			|| !ft_strncmp(tmp[i] + k, "WE", 2)
			|| !ft_strncmp(tmp[i] + k, "EA", 2))
		{
			if (!check_texture(tmp[i], k + 2))     //remove ! for actual testing with valid file
				return (1);
		}
		else if (tmp[i][k] =='F'|| tmp[i][k] == 'C')
		{
			if (check_color(tmp[i], k + 1))
				return (ft_printf("color\n"), 1);
		}
		else if (tmp[i][k] != '\n')
		{
			if (check_nbr(tmp, i, k))
				return (ft_printf("nbr\n"),1);
		}
		i++;
	}
	return (0);
}
