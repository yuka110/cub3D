/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkmap2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 13:25:53 by yitoh         #+#    #+#                 */
/*   Updated: 2024/04/09 14:01:13 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	wall_closed(char **tmp, int i, int k)
{
	if (!ft_strchr("\n\0", tmp[i - 1][0])
		&& ft_strchr(" \n\0", tmp[i - 1][k]) && tmp[i][k] == '0')
		return (1);
	if ((!tmp[i + 1] || ft_strchr(" \n\0", tmp[i + 1][k]))
		&& !ft_strchr("1 \t\n\0", tmp[i][k]))
		return (1);
	if (ft_strchr(" \t\n\0", tmp[i][k + 1])
		&& !ft_strchr("1 \t\n\0", tmp[i][k]))
		return (1);
	return (0);
}

int	check_nbr(char **tmp, int i, int k, int players)
{
	while (tmp[i])
	{
		while (tmp[i][k] && ft_strchr(" \t", tmp[i][k]))
			k++;
		if (tmp[i][k] != '1')
			return (1);
		while (tmp[i][k])
		{
			if (wall_closed(tmp, i, k))
				return (ft_printf("map wall is not properly closed\n"), 1);
			if (!ft_strchr("10NSEW \t\n\0", tmp[i][k]))
				return (ft_printf("invalid char in map\n"), 1);
			if (ft_strchr("NSEW", tmp[i][k]))
				players++;
			k++;
		}
		i++;
		k = 0;
	}
	while (tmp[i - 1][k] && ft_strchr(" \t", tmp[i - 1][k]))
		k++;
	if (i < 3 || players != 1 || !ft_strchr("\n1", tmp[i - 1][k]))
		return (1);
	return (0);
}
