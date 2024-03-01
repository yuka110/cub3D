/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testprint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/24 18:00:15 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/01 15:52:26 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_printarr(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		ft_printf(tmp[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_printintarrs(int **tmp, int width)
{
	int	i;
	int	k;

	i = 0;
	while (tmp[i])
	{
		k = 0;
		while (k < width)
		{
			if (tmp[i][k] == -1)
				ft_printf(" ");
			else
				ft_printf("%d", tmp[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}

void    ft_printints(int *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", s[i]);
		i++;
	}
	ft_printf("\n");
}


void	ft_printmap(t_map *map)
{
	ft_printf("\e[1;36mwidth of map:\e[0;00m %d\n\e[1;36mdepth of map:\e[0;00m %d\n", map->width, map->depth);
	ft_printf("\e[1;36mmap in int **:\n\e[0;00m");
	ft_printintarrs(map->map2d, map->width);
	ft_printf("\e[1;36mpx in index:\e[0;00m %d\n\e[1;36mpy in index:\e[0;00m %d\n", map->px, map->py);
	ft_printf("\e[1;31mfloor color: \e[0;00m");
	ft_printints(map->floor, 3);
	ft_printf("\e[1;31mceiling color: \e[0;00m");
	ft_printints(map->ceiling, 3);

}
