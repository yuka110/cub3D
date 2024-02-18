/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkmap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 17:43:06 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/18 19:32:44 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_checktexture(char *png)
{
	int	fd;

	fd = open(png, O_RDONLY);
	if (fd < 0)
		return (1);
	close (fd);
	return (0);
}

int	ft_checkcolor(char *color)
{
	char	**arr;
	int		i;
	int		code;

	arr = ft_split(color, ',');
	if (!arr)
		return (1);
	i = 0;
	while (arr[i])
	{
		code = ft_atoi(arr[i]);
		if (code < 0 || code > 255)
		{
			ft_freearrs(arr);
			return (1);
		}
		i++;
	}
	ft_freearrs(arr);
	return (0);
}

int	ft_checknbr(char **tmp, int i, int k)
{
	if (tmp[i][k] != '1')
		return (ft_printf("first\n"), 1);
	while (tmp[i][k])
	{
		if ((!tmp[i - 1] || ft_strchr(" \0", tmp[i - 1][k]))
			&& !ft_strchr("1 \n\0", tmp[i][k]))
			return (ft_printf("up\n"), 1);
		if ((!tmp[i + 1] || ft_strchr(" \0", tmp[i + 1][k]))
			&& !ft_strchr("1 \n\0", tmp[i][k]))
			return (ft_printf("down\n"), 1);
		if ((ft_strchr(" \n\0", tmp[i][k + 1]))
			&& !ft_strchr("1 \n\0", tmp[i][k]))
			return (ft_printf("right\n"), 1);
		if (!ft_strchr("01NSWE \n\0", tmp[i][k]))
			return (ft_printf("other\n"), 1);
		k++;
	}
	return (0);
}

int	ft_checkmap(char **tmp, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && tmp[i][k] == ' ')
			k++;
		if (!ft_strncmp(tmp[i] + k, "NO ", 3)
			|| !ft_strncmp(tmp[i] + k, "SO ", 3)
			|| !ft_strncmp(tmp[i] + k, "WE ", 3)
			|| !ft_strncmp(tmp[i] + k, "EA ", 3))
		{
			if (!ft_checktexture(tmp[i] + k + 3))
				return (1);
		}
		else if (!ft_strncmp(tmp[i] + k, "F ", 2) 
			|| !ft_strncmp(tmp[i] + k, "C ", 2))
		{
			if (ft_checkcolor(tmp[i] + k + 2))
				return (ft_printf("color\n"), 1);
		}
		else if (tmp[i][k] != '\n')
		{
			if (ft_checknbr(tmp, i, k))
				return (ft_printf("nbr\n"),1);
		}
		i++;
	}
	return (0);
}
