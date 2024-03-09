/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 17:25:02 by yitoh         #+#    #+#                 */
/*   Updated: 2024/03/09 12:09:44 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//free 2d int arrays
void	ft_freeintarrs(int **s)
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

//free 2d char arrays
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

//free map struct & show error msg
void	ft_error(char *msg, t_map *map)
{
	if (map)
	{
		if (map->map2d)
			ft_freeintarrs(map->map2d);
		if (map->floor)
			free(map->floor);
		if (map->ceiling)
			free(map->ceiling);
		if (map->n_tex)
			free(map->n_tex);
		if (map->s_tex)
			free(map->s_tex);
		if (map->w_tex)
			free(map->s_tex);
		if (map->e_tex)
			free(map->s_tex);
		free(map);
	}
	ft_printf("Error: %s\n", msg);
	exit(1);
}

//used at the end of program & exit 0
void	ft_cleanup(t_map *map)
{
	ft_freeintarrs(map->map2d);
	free(map->ceiling);
	free(map->floor);
	free(map->s_tex);
	free(map->n_tex);
	free(map->w_tex);
	free(map->e_tex);
	free(map);
	exit(0);
}
