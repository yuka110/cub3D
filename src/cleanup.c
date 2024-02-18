/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 17:25:02 by yitoh         #+#    #+#                 */
/*   Updated: 2024/02/18 17:19:03 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_freearrs(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	ft_error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

void	ft_freemap(t_map *map)
{
	free(map);
	exit(0);
}
