/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkmap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 17:43:06 by yitoh         #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2024/03/21 10:54:58 by evoronin      ########   odam.nl         */
=======
/*   Updated: 2024/03/21 11:12:04 by yitoh         ########   odam.nl         */
>>>>>>> 5d1d824 (norm a bit)
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_texture(char *png, int k)
{
	int		fd;
	char	*file;

	if (!ft_strnstr(png, ".png", ft_strlen(png)))
		return (ft_printf("png file not found "), 1);
	while (ft_strchr(" \t", png[k]))
		k++;
	file = ft_strdup(png + k);
	k = ft_strlen(file) - 1;
	while (k >= 0 && ft_strchr(" \t\n", file[k]))
	{
		file[k] = '\0';
		k--;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(file), 1);
	close (fd);
	return (free(file), 0);
}

int	count_colors(char *color, int k)
{
	int		code;

	code = 0;
	while (color[k])
	{
		if (color[k] == ',')
			code++;
		k++;
	}
	if (code != 2)
		return (1);
	return (0);
}

int	check_color(char *color, int k)
{
	char	**arr;
	int		c_code;

	if (!ft_strchr(" \t", color[k]) || count_color(color, k))
		return (1);
	arr = ft_split(color, ',');
	if (!arr)
		return (1);
	k = 0;
	while (arr[k])
	{
		c_code = ft_atoi(arr[k]);
		if (c_code < 0 || c_code > 255)
			return (ft_freearrs(arr), 1);
		k++;
	}
	return (ft_freearrs(arr), 0);
}

int	check_nbr(char **tmp, int i, int k)
{
	if (tmp[i][k] != '1')
		return (1);
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

int	check_others(char **tmp, int i, int k, int players)
{
	while (i >= 0 && tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (!ft_strchr("\n1", tmp[i][k]) && !players)
			return (1);
		if (tmp[i][k] == '1')
		{
			while (tmp[i][k])
			{
				if (ft_strchr("NSEW", tmp[i][k]))
				{
					players++;
					if ((tmp[i - 1][k] == '1' && tmp[i + 1][k] == '1'
						&& tmp[i][k + 1] == '1' && tmp[i][k - 1] == '1')
						|| players > 1)
						return (1);
				}
				k++;
			}
		}
		i--;
	}
	return (0);
}

int	ft_checkmap(char **tmp, int i, int k)
{
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if ((!ft_strncmp(tmp[i] + k, "NO", 2)
				|| !ft_strncmp(tmp[i] + k, "SO", 2)
				|| !ft_strncmp(tmp[i] + k, "WE", 2)
				|| !ft_strncmp(tmp[i] + k, "EA", 2))
			&& check_texture(tmp[i], k + 2))
			return (ft_printf("texture\n"), 1);
		else if ((tmp[i][k] == 'F' || tmp[i][k] == 'C')
				&& (check_color(tmp[i], k + 1)))
			return (ft_printf("color\n"), 1);
		else if (!ft_strchr("NSWEFC\n", tmp[i][k]) && check_nbr(tmp, i, k))
			return (ft_printf("nbr\n"), 1);
		i++;
	}
	if (check_others(tmp, i - 1, 0, 0))
		return (1);
	return (0);
}
